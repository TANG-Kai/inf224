#include"media_base.h"
#include"media_video.h"
#include"media_photo.h"
int main()
{
    Media_video* mv = new Media_video("obj1", "drop.avi",2);
    Media_base* mv_base = mv;
    mv_base->show_values(std::cout);
    mv_base->play();

    Media_photo * mp = new Media_photo("obj2", "lena_color.gif");
    mv_base = mp;
    mv_base->play();

    return 0;
}
