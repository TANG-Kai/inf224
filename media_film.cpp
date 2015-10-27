#include"media_film.h"
Media_film::Media_film():
  Media_video(),
  table_of_length(NULL)
{
  number_of_chapters = 0;
}

Media_film::Media_film(std::string name_of_object,std::string name_of_file, double l=0):
Media_video(name_of_object, name_of_file, l){
  table_of_length = new double[1];
  assert(table_of_length!= NULL);
  table_of_length[0] = l;
  number_of_chapters = 1;
}

Media_film::Media_film(std::string name_of_object,std::string name_of_file, double t_o_l[], int n):
Media_video(name_of_object, name_of_file, 0){
  assert(t_o_l != NULL && n > 0);//make sure that it's a table non-empty
  table_of_length = t_o_l;
  number_of_chapters = n;
  double sum = 0;
  for(int i=0;i< number_of_chapters;i++){
    assert(table_of_length[i]>=0);
    sum += table_of_length[i];
  }
  length = sum;
}


void Media_film::show_values(std::ostream &out) const{
  out<<number_of_chapters<<std::endl;
  for(int i=0;i< number_of_chapters;i++){
    out<<table_of_length[i]<<" ";
  }
  out<<std::endl;
}


void Media_film::set_table(double t_o_l[], int n){
  assert(t_o_l != NULL && n > 0);//make sure that it's a table non-empty
  table_of_length = t_o_l;// shouldn't delete table, because it could be
  number_of_chapters = n;

  double sum = 0;
  for(int i=0;i< number_of_chapters;i++){
    assert(table_of_length[i]>=0);
    sum += table_of_length[i];
  }
  length = sum;
}
