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

unsigned int	my_mlx_pixel_put(t_game *data, int x, int y, int n)
{
	(void)n;
	return (*(unsigned int *)(data->addr
		+(y * data->line_length1 + x * (data->bits_per_pixel1 / 8))));
}

void	draw_v2(t_game **cub)
{
	t_game	*game;
	t_ray	*r;

	game = *cub;
	r = game->ray;
	if (r->hit_is_v == 0)
	{
		if (r->angle <= M_PI && r->angle >= 0){
			game->img2 = mlx_xpm_file_to_image(game->mlx,
					game->path->no, &game->j1, &game->i1);
		}
		else
			game->img2 = mlx_xpm_file_to_image(game->mlx,
					game->path->so, &game->j1, &game->i1);
	}
	else
	{
		if (r->angle <= (3 * M_PI) / 2 && r->angle >= M_PI / 2)
			game->img2 = mlx_xpm_file_to_image(game->mlx, game->path->ea,
					&game->j1, &game->i1);
		else
			game->img2 = mlx_xpm_file_to_image(game->mlx, game->path->we,
					&game->j1, &game->i1);
	}
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

	game = *cub;
	draw_v2(cub);
	game->addr = mlx_get_data_addr(game->img2, &game->bits_per_pixel1,
			&game->line_length1, &game->endian1);
	game->y_start = (SCREEN_H - wall_height) / 2;
	game->y_end = game->y_start + wall_height;
	xgame = (game->j1 * fmod(game->ray->hit_x + game->ray->hit_y,
				game->size)) / game->size;
	draw_c(game->y_start, cub, x);
	y = game->y_start;
	while (y < game->y_end)
	{
		ygame = (game->i1 * (y - game->y_start)) / wall_height;
		color2 = my_mlx_pixel_put(*cub, xgame, ygame, 4);
		mlx_pixel_put(game->mlx, game->window, x, y, color2);
		y++;
	}
	draw_f(game->y_end, cub, x);
}
