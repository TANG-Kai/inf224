#ifndef MEDIA_LIST_H
#define MEDIA_LIST_H
#include"media_base.h"
#include <cereal/types/list.hpp>
#include<list>
class Media_list;
typedef std::shared_ptr<Media_list> mlptr;
using namespace std;
class Media_list : public list<mbptr>{
    string name;
public:
    Media_list():list(){name = "";}
    Media_list(list<mbptr>& lst,string name): list(lst){ this->name = name;}
    string get_name();
    void virtual show_values(std::ostream &out) const;
    void virtual play() const;
    friend class cereal::access;
    void virtual serialize( cereal::JSONOutputArchive & ar )
    {
    	//ar(name, (list<mbptr>)*this);//doesn't work. guess cereal don't handle complex combinations
        ar(name);
    }
};

#endif//MEDI_LIST_H
