#include "Cube.h"

void load_map(int n, t_path *load)
{
  load->map = (char **)malloc((sizeof (char *))* (n + 1));
}

int  empty_line(char *ptr)
{
  int i;

  i = 0;
  while(ptr[i])
  {
    if(ptr[i] == '0' || ptr[i] == '1' || ptr[i] == 'N' || ptr[i] == 'S' || ptr[i] == 'W' || ptr[i] == 'E'){
      return 1;
    }
    i++;
  }
  return 0;
}

int parametre_map(char *ptr, t_path *load)
{
  int i;

  i = 0;
//  if(load->C != -1 && load->F != -1 &&  load->EA && load->NO && load->SO && load->WE){
    //return(0);
  //}
  while(ptr[i]){

    if((ptr[i] == 'F' || ptr[i] == 'C'))
    {
        if((ptr[i + 1] == 9 || ptr[i + 1] == 32) && ptr[i + 2] && (ptr[i + 2] != 9 && ptr[i + 2] != 32))
        {
              load_identifier(ptr, i + 2,&load);
              return 1;
        }
    }
    if (ptr[i] == 'N' && ptr[i + 1] &&  ptr[i + 1] == 'O')
    {
        if((ptr[i + 2] == 9 || ptr[i + 2] == 32) && ptr[i + 3] && (ptr[i + 3] != 9 && ptr[i + 3] != 32))
      {
          //printf("entered\n");
            load_identifier(ptr, i + 3, &load);
            return 1;
      }
    }
    else if (ptr[i] == 'S' && ptr[i + 1] &&  ptr[i + 1] == 'O')
    {
        if((ptr[i + 2] == 9 || ptr[i + 2] == 32) && ptr[i + 3] && (ptr[i + 3] != 9 && ptr[i + 3] != 32)){
            load_identifier(ptr, i + 3, &load);
            return 1;
      }
    }
    else if (ptr[i] == 'W' && ptr[i + 1] &&  ptr[i + 1] == 'E')
    {
        if((ptr[i + 2] == 9 || ptr[i + 2] == 32) && ptr[i + 3] && (ptr[i + 3] != 9 && ptr[i + 3] != 32))
        {
            load_identifier(ptr, i + 3, &load);
            return 1;
        }

    }
    else if (ptr[i] == 'E' && ptr[i + 1] &&  ptr[i + 1] == 'A')
    {
        if((ptr[i + 2] == 9 || ptr[i + 2] == 32) && ptr[i + 3] && (ptr[i + 3] != 9 && ptr[i + 3] != 32))
        {
            load_identifier(ptr, i + 3, &load);
            return 1;
        }
    }
    i++;
  }
  return 0;
}

