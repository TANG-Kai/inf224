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

Media_film::Media_film(std::string name_of_object,std::string name_of_file, double* t_o_l, int n):
Media_video(name_of_object, name_of_file, 0){
  assert(t_o_l != NULL && n > 0);//make sure that it's a table non-empty
  table_of_length = new double[n];// do a new copy of array, so that it won't change according to the original
  number_of_chapters = n;
  for(int i=0;i<n;i++){
	table_of_length[i] = t_o_l[i];
  }
  double sum = 0;
  for(int i=0;i< number_of_chapters;i++){
    assert(table_of_length[i]>=0);
    sum += table_of_length[i];
  }
  length = sum;
}

Media_film::Media_film( const  Media_film& other): Media_video(other){//calling copy constructor of base class
    number_of_chapters = other.number_of_chapters;
    if(table_of_length != NULL) delete table_of_length;
    table_of_length = new double[number_of_chapters];
    for(int i=0;i<number_of_chapters;i++){
        table_of_length[i] = other.table_of_length[i];
    }
}

void Media_film::show_values(std::ostream &out) const{
  out<<"chapter count: "<<number_of_chapters<<' ';
  for(int i=0;i< number_of_chapters;i++){
    out<<"length of "<<i<<"th chapter: "<<table_of_length[i]<<" ";
  }
}

void Media_film::set_table(double* t_o_l, int n){//delete old table, copy values into new table
  assert(t_o_l != NULL && n > 0);//make sure that it's a table non-empty
  delete table_of_length;
  number_of_chapters = n;
  table_of_length = new double[n];
  for(int i=0;i<n;i++){
	table_of_length[i] = t_o_l[i];
  }
  double sum = 0;
  for(int i=0;i< number_of_chapters;i++){
    assert(table_of_length[i]>=0);
    sum += table_of_length[i];
  }
  length = sum;
}
