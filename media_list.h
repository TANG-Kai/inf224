#ifndef MEDIA_LIST_H
#define MEDIA_LIST_H
#include"media_base.h"
#include<list>
using namespace std;
class Media_list : public list<mbptr>{
    string name;
public:
    Media_list():list(){name = "";}
    Media_list(list<mbptr>& lst,string name): list(lst){ this->name = name;}
    string get_name();
    void virtual show_values(std::ostream &out) const;
};

#endif//MEDI_LIST_H