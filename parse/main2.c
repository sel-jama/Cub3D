/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:55:43 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/05 19:05:14 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute/cub3d.h"

void	c_main_h(char *ptr, int *n)
{
	if (ptr && empty_line(ptr) == 0)
	{
		if ((ptr[0] == 32 || ptr[0] == 9) || (ptr[0] != 'N' && ptr[0] != 'S'
				&& ptr[0] != 'W' && ptr[0] != 'E' && ptr[0] != 'F'
				&& ptr[0] != 'C' && ptr[0] != '\n'))
			ft_errors();
		free(ptr);
		ptr = NULL;
	}
	else if (ptr && empty_line(ptr) == 1)
	{
		free(ptr);
		ptr = NULL;
		*n += 1;
	}
}

int	c_main(t_path *load, char *ptr, char *av[], int n)
{
	int	j;

	j = open(av[1], F_OK, R_OK);
	if (j == -1)
		ft_errors();
	while (1)
	{
		ptr = get_next_line(j);
		if (!ptr)
		{
			free(ptr);
			break ;
		}
		c_main_h(ptr, &n);
		if (load->no && load->so && load->we && load->ea && load->f && load->c)
		{
			free(ptr);
			break ;
		}
	}
	if (ptr)
		free(ptr);
	return (n);
}

void	c_main2_h2(int i, char *tmp, t_path **load, int *l)
{
	if (tmp[i] == 'F')
	{
		*l = 1;
		if ((*load)->f_tmp == 1)
			ft_errors();
	}
	if (tmp[i] == 'C')
	{
		*l = 1;
		if ((*load)->c_tmp == 1)
			ft_errors();
	}
}
