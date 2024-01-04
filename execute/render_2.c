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

void	draw_vertical_line(t_game **cub, int x, int wall_height)
{
	t_game			*game;
	unsigned int	color2;
	int				ygame;
	int				xgame;
	int				y;
	int n;

	game = *cub;
	n = 0;
	n = draw_v2(cub);
	if(n >= 1)
	{
		if(n == 1)
		{
			game->tmp1 = game->i1;
			game->tmp_2 = game->j1;
		}
		else if(n == 2)
		{
			game->tmp1 = game->i2;
			game->tmp_2 = game->j2;
		}
		else if(n == 3)
		{
			game->tmp1 = game->i3;
			game->tmp_2 = game->j3;
		}
		else if(n == 4)
		{
			game->tmp1 = game->i4;
			game->tmp_2 = game->j4;
		}
		else if (n == 0)
			exit(0);
	}
	// game->addr = mlx_get_data_addr(game->img2, &game->bits_per_pixel1,
	// 		&game->line_length1, &game->endian1);
	game->y_start = (SCREEN_H - wall_height) / 2;
	game->y_end = game->y_start + wall_height;
	xgame = (game->tmp1 * fmod(game->ray->hit_x + game->ray->hit_y,
				game->size)) / game->size;
	draw_c(game->y_start, cub, x);
	y = game->y_start;
	while (y < game->y_end)
	{
		ygame = (game->tmp_2 * (y - game->y_start)) / wall_height;
		color2 = my_mlx_pixel_put(cub, xgame, ygame, n);
		mlx_pixel_put(game->mlx, game->window, x, y, color2);
		y++;
	}
	draw_f(game->y_end, cub, x);
}
