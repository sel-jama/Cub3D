/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:47:55 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/05 18:48:09 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
