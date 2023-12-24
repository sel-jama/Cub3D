/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_sec_funs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboucha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:11:48 by yboucha           #+#    #+#             */
/*   Updated: 2023/12/24 03:54:43 by yboucha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube.h"

void	check_map2(int i, int n, char **ptr, int *f)
{
	int		j;
	int		t;
	char	c;

	j = 0;
	while (ptr[i][j])
	{
		c = ptr[i][j];
		check_map3(i, n, c);
		if (c == '0')
		{
			t = is_rounded(ptr, i, j);
			if (t == 2)
				ft_errors();
		}
		else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			*f += 1;
			if (*f > 1)
				ft_errors();
		}
		j++;
	}
}

void	check_map(char **ptr, int n)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	if (ptr == NULL)
		exit(0);
	while (ptr[i])
	{
		check_map2(i, n, ptr, &f);
		i++;
	}
}

int	check_interput(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	i -= 1;
	if (arg[i] == 'b' && arg[i - 1] == 'u' && arg[i - 2] == 'c'
		&& arg[i - 3] == '.' && arg[i - 4])
		return (1);
	ft_putendl_fd("Error : invalid file .", 2);
	return (0);
}

void	load_path(t_path *load)
{
	load->we = NULL;
	load->so = NULL;
	load->ea = NULL;
	load->no = NULL;
	load->f = 0;
	load->c = 0;
	load->f2 = 0;
	load->f3 = 0;
	load->c2 = 0;
	load->c3 = 0;
}
