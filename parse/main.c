/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:06:54 by yboucha           #+#    #+#             */
/*   Updated: 2024/01/05 18:55:19 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute/cub3d.h"

void	c_main2_h(char **ptr, int n, t_path **load)
{
	int		i;
	char	*tmp;
	int		l;
	int		g;

	i = 0;
	l = 0;
	tmp = *ptr;
	while (tmp[i])
	{
		c_main2_h2(i, tmp, load, &l);
		if (l == 1 && tmp[i] >= '0' && tmp[i] <= '9')
			g = 1;
		i++;
	}
	if (g == 0 && l == 1)
		ft_errors();
	if (empty_line(*ptr) == 0)
	{
		if ((n >= 1 && *ptr[0] == '\n')
			|| (n >= 1 && (*ptr[0] == 32 && *ptr[0] == 9)))
			ft_errors();
		free(*ptr);
		*ptr = NULL;
	}
}

void	p_check(t_path **load)
{
	if (!(*load)->no && !(*load)->so && !(*load)->we
		&& !(*load)->ea && (*load)->c_tmp == 0
		&& (*load)->f_tmp == 0)
		ft_errors();
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
		c_main2_h(&ptr, n, &load);
		if ((ptr && parametre_map(ptr, &load) == 0 && empty_line(ptr) == 1))
		{
			p_check(&load);
			load->map[n] = ptr;
			n += 1;
		}
	}
	load->map[n] = NULL;
	check_parametre(&load);
	check_map(load->map, n - 1);
}

void	count_rows_c(t_path *load, t_game *cub)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	j = 0;
	t = 0;
	while (load->map[i])
	{
		if (j > t)
			t = j;
		j = 0;
		while (load->map[i][j])
			j++;
		i++;
	}
	cub->rows = i;
	cub->cols = t;
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
		check_double(load.map);
	}
	else
		ft_errors();
	cub.size = 32;
	count_rows_c(&load, &cub);
	start_game(&cub);
}
