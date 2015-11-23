#include "media_base.h"
#include "media_video.h"
#include "media_photo.h"
#include "media_film.h"
#include "media_list.h"
#include <iostream>
#include <string>
#include <sstream> 
#include "TCPServer.h"
#include "media_map.h"
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/archives/binary.hpp>
#include <fstream>
using namespace std;

const int DEFAULT_PORT = 3331;

class MyApp {
    std::shared_ptr<Media_map> m_map;
public:

    /// Cette fonction est appelée chaque fois qu'il y a une requête à traiter.
    /// - 'request' contient la requête
    /// - 'response' sert à indiquer la réponse qui sera renvoyée au client
    /// - si la fonction renvoie false la connexion est close.
    //
    // Cette fonction peut etre appelée en parallele par plusieurs threads (il y a
    // un thread par client).
    // Si le verrou 'lock' est bloqué en mode WRITE, les autres appels sont bloqués
    // jusqu'à la fin l'appel qui a bloqué le verrou.
    //
    MyApp(std::shared_ptr<Media_map> m_map):m_map(m_map){}
    bool processRequest(TCPServer::Cnx& cnx, const string& request, string& response)
    {
        stringstream ss ;
        ss.str(request);
        string type_of_request, content_of_request;
        ss>>type_of_request>>content_of_request;


        // mettre cette variable à true si la commande modifie les donnees du programme
        bool changeData = false;
        if (type_of_request == "delMedias" || type_of_request == "delGroups") changeData = true;

        // suivant le cas on bloque le verrou en mode WRITE ou en mode READ
        TCPServer::Lock lock(cnx, changeData);

        cerr << "request: '" << request << "'" << endl;

        // simule un traitement long (décommenter pour tester le verrou)
        // if (changeData) sleep(10); else sleep(5);

        //response = "OK: " + request;
        if(type_of_request == "show")
        {
            std::ostringstream os;
            m_map->find_and_show(content_of_request,os);
            response = os.str();
        }
        else if(type_of_request == "play")
        {
            m_map->find_and_play(content_of_request);
            response = "playing " + content_of_request + " on the server.";
        }
        else response = " ";
        cerr << "response: '" << response << "'" << endl;

        // renvoyer false pour clore la connexion avec le client
        return true;
    }
};

int main(int argc, char* argv[])
{
    std::shared_ptr<Media_video> mv(new Media_video("obj1", "drop.avi",2));
    mbptr mv_base = mv;
    //mv_base->show_values(std::cout);
    //mv_base->play();

    std::shared_ptr<Media_photo> mp(new Media_photo("obj2", "lena_color.gif"));
    mv_base = mp;
    //mv_base->play();

    std::list<mbptr> list;
    list.push_back(mv);
    list.push_back(mp);

    Media_list m_list(list,"my_list");
    //std::cout<<m_list.get_name()<<std::endl;
    //m_list.show_values(std::cout);

    std::shared_ptr<Media_map> mm(new Media_map());
    mm->add_basemedia(mv);
    mm->add_basemedia(mp);

    MyApp * app = new MyApp(mm);
    TCPServer * server = new TCPServer();
    server->setCallback(app, &MyApp::processRequest);

    int port = (argc >= 2) ? atoi(argv[1]) : DEFAULT_PORT;
    cout << "Starting Server on port " << port << endl;
    int status = server->run(port);

    if (status < 0) {
        cerr << "Could not start Server on port " << port << endl;
        return 1;
    }
    else return 0;
}
