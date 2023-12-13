#ifndef CUBE_H
#define CUBE_H


#include "../libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct path
{
    char  *NO;
    char  *SO;
    char  *WE;
    char  *EA;
    int    F;
    int    F2;
    int    F3;
    int    C;
    int    C2;
    int    C3;
    char **map;
} t_path;

void check_parametre(t_path *load);
void check_map(char **ptr, int n);
int  parametre_map(char *ptr, t_path *load);
void load_map(int n, t_path *load);
int  empty_line(char *ptr);
void load_identifier(char *ptr, int start, t_path **load);
int  check_interput(char *arg);

#endif
