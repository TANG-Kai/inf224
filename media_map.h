#ifndef MEDIA_MAP_H
#define MEDIA_MAP_H
#include"media_base.h"
#include"media_list.h"
#include<iostream>
#include<map>
using namespace std;
class Media_map{
    string mapname;
    map<string, mbptr> basemap;//a map of name and smart pointer to media_base
    map<string, mlptr> listmap;
    public:
    Media_map():basemap(),listmap(){mapname = "";}
    void add_basemedia(mbptr m);
    void add_list(mlptr list);
    void erase_by_key(string key);
    void find_and_show(string key,ostream & out);
    void find_and_play(string key);

};
#endif//MEDIA_MAP_H
