/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:45:14 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/05 18:42:24 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init2(t_game **cub)
{
	t_game	*init;

	init = *cub;
	init->img1 = NULL;
	init->img2 = NULL;
	init->img3 = NULL;
	init->img4 = NULL;
	init->i1 = 0;
	init->j1 = 0;
	init->i2 = 0;
	init->j2 = 0;
	init->i3 = 0;
	init->j3 = 0;
	init->i4 = 0;
	init->j4 = 0;
	init->tmp1 = 0;
	init->tmp_2 = 0;
	init->tmp2 = 0;
	init->wall_heigth = 0;
	init->tmp = 0;
}

void	initializer(t_game **cub)
{
	t_game	*init;

	init_dir(cub);
	init_ray(cub);
	init = *cub;
	init->window_w = init->cols * init->size;
	init->window_h = init->rows * init->size;
	init->addr = NULL;
	init->addr2 = NULL;
	init->addr3 = NULL;
	init->addr4 = NULL;
	init->bits_per_pixel1 = 0;
	init->endian1 = 0;
	init->line_length1 = 0;
	init->bits_per_pixel2 = 0;
	init->endian2 = 0;
	init->line_length2 = 0;
	init->bits_per_pixel3 = 0;
	init->endian3 = 0;
	init->line_length3 = 0;
	init->bits_per_pixel4 = 0;
	init->endian4 = 0;
	init->line_length4 = 0;
	init->data = 0;
	init2(cub);
}

void	init_ray(t_game **cub)
{
	t_ray	*init;

	init = (*cub)->ray;
	init->turn_dir = 0;
	init->walk_dir = 0;
	init->rotation_speed = 10 * M_PI / 180;
	init->num_rays = SCREEN_W;
	init->rotate_dir = 0;
}

void	init_dir(t_game **game)
{
	t_game	*p;

	p = *game;
	if (p->direction == 'S')
		(*game)->ray->rotation_angle = 90 * M_PI / 180;
	if (p->direction == 'N')
		(*game)->ray->rotation_angle = 270 * M_PI / 180;
	if (p->direction == 'W')
		(*game)->ray->rotation_angle = 360 * M_PI / 180;
	if (p->direction == 'E')
		(*game)->ray->rotation_angle = 180 * M_PI / 180;
}
