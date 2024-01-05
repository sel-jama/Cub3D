/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 06:17:44 by yboucha           #+#    #+#             */
/*   Updated: 2023/12/26 13:58:13 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	my_mlx_pixel_put(t_game **data, int x, int y, int n)
{
	if(n == 1)
	{
		return (*(unsigned int *)((*data)->addr
			+(y * (*data)->line_length1 + x * ((*data)->bits_per_pixel1 / 8))));
	}
	if(n == 2)
	{
		return (*(unsigned int *)((*data)->addr2
			+(y * (*data)->line_length2 + x * ((*data)->bits_per_pixel2 / 8))));
	}
	if(n == 3)
	{
		if(!(*data)->addr3)
			exit(1);
		return (*(unsigned int *)((*data)->addr3
			+(y * (*data)->line_length3 + x * ((*data)->bits_per_pixel3 / 8))));
	}
	return (*(unsigned int *)((*data)->addr4
		+(y * (*data)->line_length4 + x * ((*data)->bits_per_pixel4 / 8))));
}

int	draw_v2(t_game **cub)
{
	t_game	*game;
	t_ray	*r;
	int i;

	i = 0;
	game = *cub;
	r = game->ray;
	if (r->hit_is_v == 0)
	{
		if (r->angle <= M_PI && r->angle >= 0)
					i = 1;
		else
					i = 2;
	}
	else
	{
		if (r->angle <= (3 * M_PI) / 2 && r->angle >= M_PI / 2)
			i = 3;
		else
			i = 4;	
	}
	return(i);
}

void	draw_c(int y_start, t_game **cub, int x)
{
	int				j;
	t_game			*game;
	t_path			*p;
	unsigned int	celling;

	j = 0;
	game = *cub;
	p = game->path;
	celling = p->c * 256 * 256 + p->c2 * 256 + p->c3;
	while (j < y_start)
	{
		mlx_pixel_put(game->mlx, game->window, x, j, celling);
		j++;
	}
}

void	draw_f(int y_end, t_game **cub, int x)
{
	int				j;
	t_game			*game;
	t_path			*p;
	unsigned int	floor;

	j = y_end;
	game = *cub;
	p = game->path;
	floor = p->f * 256 * 256 + p->f2 * 256 + p->f3;
	while (j < SCREEN_H)
	{
		mlx_pixel_put(game->mlx, game->window, x, j, floor);
		j++;
	}
}

void	ft_helper(t_game **cub, int i, int j)
{
	t_game	*game;

	game = *cub;
	game->tmp1 = i;
	game->tmp_2 = j;
}

void	draw_v3(t_game **cub, int n)
{
	t_game	*game;

	game = *cub;
	if(n == 1)
		ft_helper(cub, game->i1, game->j1);
	else if(n == 2)
		ft_helper(cub, game->i2, game->j2);
	else if(n == 3)
		ft_helper(cub, game->i3, game->j3);
	else if(n == 4)
		ft_helper(cub, game->i4, game->j4);
	else if (n == 0)
		exit(0);
}

void	draw_vertical_line(t_game **cub, int x, int wall_height)
{
	unsigned int	color2;
	int				ygame;
	int				xgame;
	int				y;
	int n;

	n = 0;
	n = draw_v2(cub);
	if(n >= 1)
		draw_v3(cub, n);
	(*cub)->y_start = (SCREEN_H - wall_height) / 2;
	(*cub)->y_end = (*cub)->y_start + wall_height;
	xgame = ((*cub)->tmp1 * fmod((*cub)->ray->hit_x + (*cub)->ray->hit_y,
				(*cub)->size)) / (*cub)->size;
	draw_c((*cub)->y_start, cub, x);
	y = (*cub)->y_start;
	while (y < (*cub)->y_end)
	{
		ygame = ((*cub)->tmp_2 * (y - (*cub)->y_start)) / wall_height;
		color2 = my_mlx_pixel_put(cub, xgame, ygame, n);
		mlx_pixel_put((*cub)->mlx, (*cub)->window, x, y, color2);
		y++;
	}
	draw_f((*cub)->y_end, cub, x);
}
