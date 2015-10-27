#ifndef MEDIA_VIDEO_H
#define MEDIA_VIDEO_H
#include"media_base.h"

class Media_video : public Media_base
{
protected:
    double length;

public:
    Media_video();
    Media_video(std::string name_of_object,std::string name_of_file, double l);
    void virtual play() const;
    void virtual show_values(std::ostream &out) const;
    double virtual get_length() const;
};

#endif // MEDIA_VIDEO_H
