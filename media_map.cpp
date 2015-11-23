#include"media_map.h"
using namespace std;
void Media_map::add_basemedia(string name,mbptr m){
    map<string, mbptr>::iterator it;
    it = basemap.find(name);
    if(it!= basemap.end())
        cout<<"already in map, failed to add "<<name;
    else
        basemap[name]  = m;
}

void Media_map::add_list(string name, mlptr list){
    map<string, mlptr>::iterator it;
    it = listmap.find(name);
    if(it!= listmap.end())
        cout<<"already in map, failed to add "<<name;
    else
        listmap[name]  = list;
}

void Media_map::erase_by_key(string key){
    map<string, mlptr>::iterator itml;
    map<string, mbptr>::iterator itmb;

    itmb = basemap.find(key);
    itml = listmap.find(key);

    if(itmb != basemap.end())
        basemap.erase(itmb);
    else if(itml != listmap.end())
        listmap.erase(itml);
    else// can't find proper key
        cout<<"can't erase this key: "<<key;
}
void Media_map::find_and_show(string key,ostream &out){
    map<string, mlptr>::iterator itml;
    map<string, mbptr>::iterator itmb;

    itmb = basemap.find(key);
    itml = listmap.find(key);

    if(itmb != basemap.end()){
        itmb->second->show_values(out);
    }
    else if(itml != listmap.end()){
        itml->second->show_values(out);
    }
    else// can't find proper key
        cout<<"can't find_and_show this key: "<<key;
}

void Media_map::find_and_play(string key){

    map<string, mlptr>::iterator itml;
    map<string, mbptr>::iterator itmb;

    itmb = basemap.find(key);
    itml = listmap.find(key);

    if(itmb != basemap.end()){
        itmb->second->play();
    }
    else if(itml != listmap.end()){
        itml->second->play();
    }
    else// can't find proper key
        cout<<"can't find_and_play this key: "<<key;
}

