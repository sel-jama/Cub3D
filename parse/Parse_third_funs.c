/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_third_funs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:24:17 by yboucha           #+#    #+#             */
/*   Updated: 2023/12/26 13:25:06 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube.h"
#include <stdio.h>
#include <stdlib.h>

char	*load_identifier_3(char *str, char *ptr)
{
	str = malloc(sizeof(char) * ft_strlen(ptr + 2) + 1);
	ft_strlcpy(str, ptr + 3, ft_strlen(ptr) - 3);
	//free str here
	free(str);
	str = ft_strtrim(str, "   ");
	return (str);
}

void	load_identifier_4(char *ptr, char **vpr, t_path **tmp, char *str)
{
	(void)str;
	if (ptr[0] == 'F' || ptr[0] == 'C')
	{
		if (ptr[0] == 'F')
		{
			check_numbers(vpr);
			if (ft_strlen(vpr[0]) > 11 || ft_strlen(vpr[1]) > 11
				|| ft_strlen(vpr[2]) > 11)
				ft_errors();
			//free here 3 times
			(*tmp)->f = ft_atoi(ft_strtrim(vpr[0], " "));
			(*tmp)->f2 = ft_atoi(ft_strtrim(vpr[1], " "));
			(*tmp)->f3 = ft_atoi(ft_strtrim(vpr[2], " "));
		}
		else
		{
			check_numbers(vpr);
			if (ft_strlen(vpr[0]) > 11 || ft_strlen(vpr[1]) > 11
				|| ft_strlen(vpr[2]) > 11)
				ft_errors();
			//free here 3 times
			(*tmp)->c = ft_atoi(ft_strtrim(vpr[0], " "));
			(*tmp)->c2 = ft_atoi(ft_strtrim(vpr[1], " "));
			(*tmp)->c3 = ft_atoi(ft_strtrim(vpr[2], " "));
		}
	}
	//free vpr
}

void	load_identifier_5h(char *str, char *ptr, t_path **tmp, int j)
{
	if (ptr[0] == 'W')
	{
		if ((str[j - 4] == '.') && (str[j - 3] == 'x')
			&& (str[j - 2] == 'p') && (str[j -1] == 'm'))
			(*tmp)->we = str;
		else
			ft_errors();
	}
	else if (ptr[0] == 'E')
	{
		if ((str[j - 4] == '.') && (str[j - 3] == 'x')
			&& (str[j - 2] == 'p') && (str[j -1] == 'm'))
			(*tmp)->ea = str;
		else
			ft_errors();
	}
	//free str
	//free ptr
}

void	load_identifier_5(char *str, char *ptr, t_path **tmp)
{
	int	j;

	j = ft_strlen(str);
	if (ptr[0] == 'N' && ptr[1] == 'O')
	{
		if ((str[j - 4] == '.') && (str[j - 3] == 'x')
			&& (str[j - 2] == 'p') && (str[j -1] == 'm'))
			(*tmp)->no = str;
		else
			ft_errors();
	}
	else if (ptr[0] == 'S')
	{
		if ((str[j - 4] == '.') && (str[j - 3] == 'x')
			&& (str[j - 2] == 'p') && (str[j -1] == 'm'))
			(*tmp)->so = str;
		else
			ft_errors();
	}
	load_identifier_5h(str, ptr, tmp, j);
}

void	load_identifier(char *ptr, int start, t_path **load)
{
	t_path	*tmp;
	char	*str;
	char	**vpr;
	int		g;
	int		l;

	(void)start;
	str = NULL;
	g = 0;
	vpr = NULL;
	l = 0;
	tmp = *load;
	if (ptr[0] == 'F' || ptr[0] == 'C')
		vpr = load_identifier_2(l, ptr, vpr, g);
	else
		str = load_identifier_3(str, ptr);
	if (str || vpr)
	{
		load_identifier_4(ptr, vpr, load, str);
		load_identifier_5(str, ptr, &tmp);
	}
}
