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

#include "../execute/cub3d.h"
#include "Cube.h"
#include <stdio.h>

char	*load_identifier_3(char *str, char *ptr)
{
	char *tmp = NULL;
	char *tmp2 = NULL;
	tmp = ptr + 3;
	printf("%s\n", ptr);
	if(ptr[0] != 'N' && ptr[0] != 'S' && ptr[0] != 'W' && ptr[0] != 'E' &&  ptr[0] != 'F' && ptr[0] != 'C')
		ft_errors();
	str = malloc(sizeof(char) * ft_strlen(ptr + 3) + 1);
	ft_strlcpy(str, tmp, ft_strlen(ptr) - 3);
	// free(str);
	// free(str);
	// printf("%s\n", str);
	tmp2 = ft_strtrim(str, "   ");
	if(!tmp2)
		ft_errors();
	free(str);
	return (tmp2);
}

void	load_identifier_4(char *ptr, char **vpr, t_path **tmp, char *str)
{
	(void)str;
	char *tmp2 = NULL;
	printf("%c\n", ptr[0]);
	if (ptr[0] == 'F' || ptr[0] == 'C')
	{
		if (ptr[0] == 'F')
		{
      		if((*tmp)->f_tmp == 1)
        		ft_errors();
			check_numbers(vpr);
			if (ft_strlen(vpr[0]) > 11 || ft_strlen(vpr[1]) > 11
				|| ft_strlen(vpr[2]) > 11)
				ft_errors();
			//free here 3 times
			tmp2 = ft_strtrim(vpr[0], " ");
			if(tmp2[0] == '\0')
				ft_errors();
			(*tmp)->f = ft_atoi(tmp2);
			free(tmp2);
			tmp2 = ft_strtrim(vpr[1], " ");
			(*tmp)->f2 = ft_atoi(tmp2);
			free(tmp2);
			tmp2 = ft_strtrim(vpr[2], " ");
			(*tmp)->f3 = ft_atoi(tmp2);
			free(tmp2);
      		(*tmp)->f_tmp = 1;
			// clean_up(vpr);
			// free(vpr[0]);
			// free(vpr[1]);
			// free(vpr[2]);
			// free(vpr[3]);
			// free(vpr);
		}
		else
		{
					printf("hi\n");
					if ((*tmp)->c_tmp == 1)
						ft_errors();
					check_numbers(vpr);
					if (ft_strlen(vpr[0]) > 11 || ft_strlen(vpr[1]) > 11
						|| ft_strlen(vpr[2]) > 11)
						ft_errors();
					//free here 3 times
					tmp2 = ft_strtrim(vpr[0], " ");
					(*tmp)->c = ft_atoi(tmp2);
					free(tmp2);
					tmp2 = ft_strtrim(vpr[1], " ");
					(*tmp)->c2 = ft_atoi(tmp2);
					free(tmp2);
					tmp2 = ft_strtrim(vpr[2], " ");
					(*tmp)->c3 = ft_atoi(tmp2);
					free(tmp2);
					(*tmp)->c_tmp = 1;
			// free(vpr[0]);
			// free(vpr[1]);
			// free(vpr[2]);
			// free(vpr[3]);
			// free(vpr[4]);
			// free(vpr);
		}
	}
	else if (vpr)
		clean_up(vpr);
	// else
	// 	ft_errors();
	//free vpr
}

void	load_identifier_5h(char *str, char *ptr, t_path **tmp, int j)
{
	if (ptr[0] == 'W' && ptr[1] == 'E' && str[0] != '\0')
	{
		if (!(*tmp)->we && str[j - 1] && (str[j - 4] == '.') && (str[j - 3] == 'x')
			&& (str[j - 2] == 'p') && (str[j -1] == 'm'))
			(*tmp)->we = str;
		else
			ft_errors();
	}
	else if (ptr[0] == 'E' && ptr[1] == 'A' && str[0] != '\0')
	{
		if (!(*tmp)->ea && str[j - 1] && (str[j - 4] == '.') && (str[j - 3] == 'x')
			&& (str[j - 2] == 'p') && (str[j -1] == 'm'))
			(*tmp)->ea = str;
		else
			ft_errors();
	}
}

void	load_identifier_5(char *str, char *ptr, t_path **tmp)
{
	int	j;

	j = ft_strlen(str); 
	if ( ptr[0] == 'N' && ptr[1] == 'O' && str[0] != '\0')
	{
		if (!(*tmp)->no && str[j - 1] && (str[j - 4] == '.') && (str[j - 3] == 'x')
			&& (str[j - 2] == 'p') && (str[j -1] == 'm'))
			(*tmp)->no = str;
		else
			ft_errors();
	}
	else if (ptr[0] == 'S' && ptr[1] == 'O' && str[0] != '\0')
	{
		if (!(*tmp)->so && str[j - 1] && (str[j - 4] == '.') && (str[j - 3] == 'x')
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
	free(ptr);
}
