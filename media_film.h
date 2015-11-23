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
    Media_film( const Media_film& other);//copy constructor, since there are a table
    Media_film(std::string name_of_object,std::string name_of_file, double* table_of_length, int number_of_chapters);//we create a new table and copy the values in given table
    void virtual show_values(std::ostream &out) const;
    void virtual set_table(double* table_of_length, int number_of_chapters);
    ~Media_film(){ if(table_of_length!=NULL) delete table_of_length;}

    friend class cereal::access;
    void virtual serialize( cereal::JSONOutputArchive & ar )
    {
      ar( cereal::base_class<Media_video>( this ), number_of_chapters);//doesn't support raw pointer, so no table_of_length
    }

};

#endif // MEDIA_FILM_H
