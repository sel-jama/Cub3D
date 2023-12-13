#include "Cube.h"


void check_parametre(t_path *load)
{
  if(load){
    if (load->C > 255 || load->C < 0)
    {
      ft_putendl_fd("Error : invalid map .", 2);
      exit(1);
    }
    if (load->C2 > 255 || load->C2 < 0)
    {
      ft_putendl_fd("Error : invalid map .", 2);
      exit(1);
    }
    if (load->C3 > 255 || load->C3 < 0)
    {
      ft_putendl_fd("Error : invalid map .", 2);
      exit(1);
    }
    if (load->F > 255 || load->F < 0)
    {
      ft_putendl_fd("Error : invalid map .", 2);
      exit(1);
    }
    if (load->F2 > 255 || load->F2 < 0)
    {
      ft_putendl_fd("Error : invalid map .", 2);
      exit(1);
    }
    if (load->F3 > 255 || load->F3 < 0)
    {
      ft_putendl_fd("Error : invalid map .", 2);
      exit(1);
    }
  }
}

void load_identifier(char *ptr, int start, t_path **load)
{
//  int i;
  t_path *tmp;
  char *str;
  char **vpr;
    int g;
//  char *tmp2;

  str = NULL;
  tmp = *load;
  if (ptr[start - 2] == 'F' || ptr[start - 2] == 'C') {
    int l;

    l = start;
    g = 0;
    while (ptr[l] && ptr[l] != '\n') {
      if (ptr[l] == ',') {
          g+=1;
      }
      if(ptr[l] != ',' && (ptr[l]  > '9' || ptr[l] < '0')){
        printf("----------%c\n", ptr[l]);
        ft_putendl_fd("Error : invalid parametere .", 2);
        exit(1);
      }
      l++;
    }
    if (g > 2)
    {
      ft_putendl_fd("Error : invalid parametere .", 2);
      exit(1);
    }
    vpr =ft_split(ptr + start, ',');
  }
  else {
      str = malloc(sizeof(char)* ft_strlen(ptr + start) + 1);
      //i = start;
      ft_strlcpy(str, ptr + start, ft_strlen(ptr) - start);

  }
  if(str)
  {

      if(ptr[start - 2] == 'F' || ptr[start - 2] == 'C')
      {
   //       printf("entered2\n");
          if (ptr[start -2] == 'F')
          {
            tmp->F = ft_atoi(vpr[0]);
            tmp->F2 = ft_atoi(vpr[1]);
            tmp->F3 = ft_atoi(vpr[2]);
          }

          else
          {
              tmp->C = ft_atoi(vpr[0]);
              tmp->C2 = ft_atoi(vpr[1]);
              tmp->C3 = ft_atoi(vpr[2]);
          }
      }
      else if (ptr[start - 3] == 'N') {
        tmp->NO = str;
      }
      else if(ptr[start - 3] == 'S'){
        tmp->SO = str;
      }
      else if(ptr[start - 3] == 'W'){
        tmp->WE = str;
      }
      else if(ptr[start - 3] == 'E'){
        tmp->EA = str;
      }
  }
}


