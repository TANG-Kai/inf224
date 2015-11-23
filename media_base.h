#ifndef MEDIA_BASE_H
#define MEDIA_BASE_H
#include <iostream>
#include <string>
#include <assert.h>
#include <memory>
#include <cereal/types/string.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/types/base_class.hpp>
	

class Media_base;
typedef std::shared_ptr<Media_base> mbptr;
class Media_base{
    std::string name_of_object,name_of_file;
public:
    Media_base(void);
    Media_base(std::string name,std::string name_of_file);
    std::string get_name() const;
    std::string  get_file_name() const;
    void set_name(std::string name_of_object);
    void set_file_name(std::string name_of_file);
    void virtual show_values(std::ostream &out) const;
    virtual void play() const = 0 ;

    friend class cereal::access;
    void virtual serialize( cereal::JSONOutputArchive & ar )
    {
      ar(name_of_object,name_of_file);
    }


};


#endif // MEDIA_BASE_H
