/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:41:18 by yboucha           #+#    #+#             */
/*   Updated: 2024/01/05 19:09:56 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct path
{
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	int					f_tmp;
	int					c_tmp;
	unsigned int		f;
	unsigned int		f2;
	unsigned int		f3;
	unsigned int		c;
	unsigned int		c2;
	unsigned int		c3;
	char				**map;
	char				*box;
}	t_path;

void	ft_errors(void);
int		is_rounded(char **ptr, int i, int j);
void	load_path(t_path *load);
void	check_parametre(t_path **load_2);
void	check_map(char **ptr, int n);
int		parametre_map(char *ptr, t_path **load_2);
void	load_map(int n, t_path **load);
int		empty_line(char *ptr);
void	check_double(char **ptr);
void	load_identifier(char *ptr, int start, t_path **load);
int		check_interput(char *arg);
void	check_numbers(char **vpr);
void	check_map3(int i, int n, char c);
char	**load_identifier_2(int l, char *ptr, char **vpr, int g);
void	c_main_h(char *ptr, int *n);
int		c_main(t_path *load, char *ptr, char *av[], int n);
void	c_main2_h2(int i, char *tmp, t_path **load, int *l);
int		norming(char **p, t_path **load, char **s, int i);
char	*norming2(char **p, char **s, char *f_or_c);
void	load_identifier_5(char *str, char *ptr, t_path **tmp);
void	load_identifier(char *ptr, int start, t_path **load);
char	*load_identifier_3(char *str, char *ptr);
void	load_identifier_4h(char **vpr, t_path **tmp, char *tmp2);
void	load_identifier_4h2(char **vpr, t_path **tmp, char *tmp2);
void	load_identifier_4(char *ptr, char **vpr, t_path **tmp, char *str);
void	load_identifier_5h(char *str, char *ptr, t_path **tmp, int j);

#endif
