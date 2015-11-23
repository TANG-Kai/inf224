#include "media_photo.h"

Media_photo::Media_photo()
    :Media_base(),x(0),y(0)
{

}

Media_photo::Media_photo(std::string name, std::string filename, double x, double y)
    :Media_base(name,filename),x(x),y(y)
{

}

void Media_photo::play() const
{

    std::string command;
    command =  "imagej "+  this->get_file_name() + " &";
    std::system(command.c_str());

}

void Media_photo::show_values(std::ostream &out) const
{
    Media_base::show_values(out);
    out<<"length: "<<x<<" width: "<<y<<' ';

}
