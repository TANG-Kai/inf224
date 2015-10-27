#ifndef MEDIA_FILM_H
#define MEDIA_FILM_H
#include"media_video.h"

class Media_film: public Media_video
{
    double* table_of_length;
    int number_of_chapters;

public:
    Media_film();
    Media_film(std::string name_of_object,std::string name_of_file, double length);// create a new table to conclude the array
    Media_film(std::string name_of_object,std::string name_of_file, double table_of_length[], int number_of_chapters);//we create a new table and copy the values in given table
    void virtual show_values(std::ostream &out) const;
    void virtual set_table(double table_of_length[], int number_of_chapters);
};

#endif // MEDIA_FILM_H
