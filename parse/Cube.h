/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboucha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:41:18 by yboucha           #+#    #+#             */
/*   Updated: 2023/12/24 05:56:21 by yboucha          ###   ########.fr       */
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
#endif
