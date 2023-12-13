#include "Cube.h"

int is_rounded(char **ptr, int i, int j)
{
//  printf("heh\n");
  if ((ptr[i - 1]) && ((ptr[i - 1][j] == 32 || ptr[i - 1][j] == 9) || ((ptr[i][j+1] == 32 || ptr[i][j + 1] == 9))))
    return 2;
  if (ptr[i + 1] && ((ptr[i + 1][j] == 32 || ptr[i+1][j] == 9) || (!ptr[i][j - 1] || (ptr[i][j - 1] == 32 || ptr[i][j - 1] == 9)))) 
    return 2;
  if(ptr[i - 1][j] == '1' && ptr[i][j + 1] == '1' && ptr[i][j - 1] == 1 && ptr[i + 1][j] == 1)
    return 2;
  if (!ptr[i + 1][j])
    return 2;
  return(1);
}

void check_double(char **ptr, int i, int j)
{
  char c;

  j++;
  while (ptr[i]) 
  {
    while (ptr[i][j]) 
    {
      c = ptr[i][j];
      printf("-%c", c);
      if (c == 'N' || c == 'S' || c == 'W' || c == 'E') 
      {
        ft_putendl_fd("Error : invalid map.", 2);
        exit(1);
      }
      j++;
    }
    i++;
  }
}

void check_map(char **ptr, int n)
{
  int i;
  int f;
  int j;
  int t;
  char c;

  i = 0;
  f = 0;
  t  = 0;
  j  = 0;
  if(ptr == NULL)
    exit(0);
  while(ptr[i])
  {
    j = 0;
    while (ptr[i][j]) 
    {
      c = ptr[i][j];
      if((i == n || i == 0) && (c != 32 && c != 9 && c!= '\n'&& c != '1'))
      {
        printf("test\n");
        ft_putendl_fd("Error : invalid map.", 2);
        exit(1);
      }
      else if((i != 0 && i != n) && (c  != '1' && c != '0' && c != 'N' && c != 'S' && c != 'W' && c != 'E' && c != 32 && c != 9 && c != '\n'))
      {
        printf("heheee\n");
        ft_putendl_fd("Error : invalid map.", 2);
        exit(1);
      }
      else if(c =='0')
      {
        t = is_rounded(ptr, i, j);
        if (t == 2) {
          printf("test2\n");
          ft_putendl_fd("Error : invalid map.", 2);
          exit(1);
        }
      }
      else if(c ==  'N' || c == 'S' || c == 'E' || c == 'W')
      {
        f+=1;
        if(f > 1)
        {
          printf("test3\n");
          ft_putendl_fd("Error : invalid map.", 2);
          exit(1);
        }
      }
      j++;
    }
    i++;
  }
}

int check_interput(char *arg){
  int i;
//  int j;


  //j = 0;
  i = 0;
  while(arg[i]){
    i++;
  }
  i -= 1;
  if(arg[i] == 'b' && arg[i - 1] == 'u' && arg[i - 2] == 'c'
      && arg[i - 3] == '.' && arg[i - 4])
  {
    return 1;
  }
  ft_putendl_fd("Error : invalid file .", 2);
  return(0);
}

void load_path(t_path *load)
{
  load->WE = NULL;
  load->SO = NULL;
  load->EA = NULL;
  load->NO = NULL;
  load->F = -1;
  load->C = -1;
  load->F2 = -1;
  load->F3 = -1;
  load->C2 = -1;
  load->C3 = -1;
}

