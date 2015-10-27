#ifndef MEDIA_PHOTO_H
#define MEDIA_PHOTO_H
#include"media_base.h"
class Media_photo : public Media_base
{
    double x,y;

public:
    Media_photo();
    Media_photo(std::string name , std::string filename, double x=0,  double y=0);
    void virtual play() const;
    void virtual show_values(std::ostream &out) const;
};

#endif // MEDIA_PHOTO_H
