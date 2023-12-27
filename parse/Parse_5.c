/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboucha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 05:54:30 by yboucha           #+#    #+#             */
/*   Updated: 2023/12/24 05:54:35 by yboucha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute/cub3d.h"

void	ft_errors(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	check_numbers(char **vpr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vpr[i] && i < 3)
	{
		j = 0;
		while (vpr[i][j])
		{
			if (j != 0 && (vpr[i][j] == 32 || vpr[i][j] == 9) &&
				(vpr[i][j + 1] >= '0' && vpr[i][j + 1] <= '9')
					&& (vpr[i][j - 1] >= '0' && vpr[i][j - 1] <= '9'))
				ft_errors();
			j++;
		}
		i++;
	}
}

void	check_parametre(t_path **load_2)
{
	t_path	*load;

	load = *load_2;
	if (load)
	{
		if (load->c > 255 || load->c < 0)
			ft_errors();
		if (load->c2 > 255 || load->c2 < 0)
			ft_errors();
		if (load->c3 > 255 || load->c3 < 0)
			ft_errors();
		if (load->f > 255 || load->f < 0)
			ft_errors();
		if (load->f2 > 255 || load->f2 < 0)
			ft_errors();
		if (load->f3 > 255 || load->f3 < 0)
			ft_errors();
	}
}

char	**load_identifier_2(int l, char *ptr, char **vpr, int g)
{
	l = 2;
	g = 0;
	char *tmp = NULL;
	while (ptr[l] && ptr[l] != '\n')
	{
		if (ptr[l] == ',')
			g += 1;
		if ((ptr[l] != 32 && ptr[l] != 9 && ptr[l] != ',')
			&& (ptr[l] > '9' || ptr[l] < '0'))
			ft_errors();
		l++;
	}
	if (g > 2 || g == 0)
		ft_errors();
	tmp = ptr + 2;
	vpr = ft_split(tmp, ',');
	if (vpr == NULL || vpr[0] == NULL || vpr[1] == NULL || vpr[2] == NULL)
		ft_errors();
	return (vpr);
}
