/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_third_fun2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:03:28 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/05 19:05:22 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute/cub3d.h"

void	load_identifier_5(char *str, char *ptr, t_path **tmp)
{
	int	j;

	j = ft_strlen(str);
	if ((ptr[0] == 'N' && ptr[1] == 'O' && (*tmp)->no)
		|| (ptr[0] == 'S' && ptr[1] == 'O' && (*tmp)->so))
		ft_errors();
	if (ptr[0] == 'N' && ptr[1] == 'O' && str[0] != '\0' && !(*tmp)->no)
	{
		if (!(*tmp)->no && str[j - 1] && (str[j - 4] == '.')
			&& (str[j - 3] == 'x') && (str[j - 2] == 'p') && (str[j -1] == 'm'))
			(*tmp)->no = str;
	}
	else if (ptr[0] == 'S' && ptr[1] == 'O' && str[0] != '\0' && !(*tmp)->so)
	{
		if (!(*tmp)->so && str[j - 1] && (str[j - 4] == '.')
			&& (str[j - 3] == 'x') && (str[j - 2] == 'p') && (str[j -1] == 'm'))
			(*tmp)->so = str;
	}
	else if (ptr[0] == 'N' && ptr[1] == 'O')
		ft_errors();
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
	if ((ptr[0] == 'C' && (*load)->c_tmp == 1)
		|| (ptr[0] == 'F' && (*load)->f_tmp == 1))
		ft_errors();
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
