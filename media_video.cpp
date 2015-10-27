#include "media_video.h"
Media_video::Media_video()
    : Media_base(),length(0)
{
}


Media_video::Media_video(std::string name_of_object,std::string name_of_file, double l=0)
    : Media_base(name_of_object,name_of_file), length(l)
{

}

void Media_video::play() const
{
    std::string command;
    command =  "mpv "+  this->get_file_name() + " &";
    std::system(command.c_str());

}

void  Media_video::show_values(std::ostream &out) const
{
    Media_base::show_values(out);
    out<<get_length()<<std::endl;

}

double  Media_video::get_length() const
{
    return length;
}
