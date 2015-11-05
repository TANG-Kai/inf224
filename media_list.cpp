#include"media_list.h"
#include"media_base.h"
#include<list>
using namespace std;
string Media_list::get_name(){
    return name;
}
void Media_list::show_values(std::ostream &out) const{
    for(Media_list::const_iterator it = begin();it!=end();++it){
       (*it)->show_values(out);
    }
}
