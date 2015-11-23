#ifndef MEDIA_MAP_H
#define MEDIA_MAP_H
#include"media_base.h"
#include"media_list.h"
#include <cereal/types/map.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <iostream>
#include <map>
using namespace std;
class Media_map{
    string mapname;
    std::map<std::string, mbptr> basemap;//a map of name and smart pointer to media_base
    std::map<std::string, mlptr> listmap;
    public:
    Media_map():basemap(),listmap(){mapname = "";}
    void add_basemedia(mbptr m);
    void add_list(mlptr list);
    void erase_by_key(string key);
    void find_and_show(string key,ostream & out);
    void find_and_play(string key);

    friend class cereal::access;
    void virtual serialize( cereal::JSONOutputArchive & ar )
    {
      //ar(mapname, CEREAL_NVP(basemap),CEREAL_NVP(listmap));   //doesn't work as expected, error from cereal. guess can't use complicate map
        ar(mapname);
    }
};
#endif//MEDIA_MAP_H
