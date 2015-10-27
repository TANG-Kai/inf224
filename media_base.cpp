#include"media_base.h"


Media_base::Media_base(void)
{
    name_of_object = "";
    name_of_file = "";
}

Media_base::Media_base(std::string  name_of_object, std::string  name_of_file)
{
    this->name_of_object = name_of_object;
    this->name_of_file = name_of_file;
}

void Media_base::set_name(std::string const name_of_object)
{
    this->name_of_object = name_of_object;
}

void Media_base::set_file_name(std::string const name_of_file)
{
    this->name_of_file = name_of_file;
}

void Media_base::show_values(std::ostream &out) const
{
    out<<name_of_object<<std::endl;
    out<<name_of_file<<std::endl;
}

std::string  Media_base::get_name() const
{
    return name_of_object;
}

std::string  Media_base::get_file_name() const
{
    return name_of_file;
}

