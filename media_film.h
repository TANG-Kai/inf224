#ifndef MEDIA_FILM_H
#define MEDIA_FILM_H
#include"media_video.h"

class Media_video : public Media_video
{
    double[] table_of_length;
    int number_of_chapters;

public:
    Media_film();
    Media_film(std::string name_of_object,std::string name_of_file, double length);// create a new table to conclude the array
    Media_film(std::string name_of_object,std::string name_of_file, double[] table_of_length, int number_of_chapters);//the member pointer will direct to the array submit.
    void virtual play() const;
    void virtual show_values(std::ostream &out) const;
    double virtual get_length() const;
};

#endif // MEDIA_FILM_H
