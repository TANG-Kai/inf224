#include<media_film.h>
Media_film::Media_film():
  Media_video()
{
}

Media_film::Media_film(std::string name_of_object,std::string name_of_file, double l=0):
Media_video(name_of_object, name_of_file, l){
  table_of_length = new double[1];
  assert(table_of_length!= NULL);
  table_of_length[0] = l;
  number_of_chapters = 1;
}

Media_film::Media_film(std::string name_of_object,std::string name_of_file, double[] t_o_l, int n):
Media_video(name_of_object, name_of_file){
  assert(t_o_l != NULL && n > 0);//make sure that it's a table non-empty
  table_of_length = t_o_l;
  number_of_chapters = n;
}
