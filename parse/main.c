/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboucha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:06:54 by yboucha           #+#    #+#             */
/*   Updated: 2023/12/24 00:11:00 by yboucha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../execute/cub3d.h"
#include <stdio.h>
#include <stdlib.h>

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
			break ;
		if (empty_line(ptr) == 1)
			n += 1;
		if (load->no && load->so && load->we && load->ea && load->f && load->c)
		{
			free(ptr);
			break ;
		}
		free(ptr);
	}
	return (n);
}

void	c_main2(t_path *load, char *ptr, char *av[], int n)
{
	int	t;

	t = open(av[1], F_OK, R_OK);
	if (t == -1)
		ft_errors();
	load_map(n, &load);
	n = 0;
	ptr = NULL;
	while (1)
	{
		ptr = get_next_line(t);
		if (ptr == NULL)
			break ;
		if (parametre_map(ptr, &load) == 0 && empty_line(ptr) == 1)
		{
			load->map[n] = malloc(sizeof(char) * (ft_strlen(ptr) + 1));
			load->map[n] = ptr;
			n += 1;
		}
	}
	load->map[n] = NULL;
	check_parametre(&load);
	check_map(load->map, n - 1);
}

int	main(int ac, char *av[])
{
	t_game	cub;
	t_ray	ray;
	t_path	load;
	char	*ptr;
	int		n;

	cub.ray = &ray;
	cub.path = &load;
	n = 0;
	ptr = NULL;
	if (ac == 2)
	{
		load_path(&load);
		if (check_interput(av[1]) == 0)
			return (0);
		n = c_main(&load, ptr, av, n);
		c_main2(&load, ptr, av, n);
	}
	else
		ft_errors();
	cub.size = 32;
	cub.rows = 14;
	cub.cols = 33;
	start_game(&cub);
}
