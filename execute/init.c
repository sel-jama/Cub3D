/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:45:14 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/22 23:45:07 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initializer(t_game **cub)
{
	t_game	*init;

	init_dir(cub);
	init_ray(cub);
	init = *cub;
	init->window_w = init->cols * init->size;
	init->window_h = init->rows * init->size;
	init->addr = NULL;
	init->bits_per_pixel = 0;
	init->endian = 0;
	init->tmp = 0;
	init->img2 = NULL;
	init->line_length = 0;
	init->i = 0;
	init->tmp2 = 0;
	init->j = 0;
	init->ray->num_rays = init->window_w ;
}

void	init_ray(t_game **cub)
{
	t_ray	*init;

	init = (*cub)->ray;
	init->turn_dir = 0;
	init->walk_dir = 0;
	init->rotation_speed = 20 * M_PI / 180;
	init->num_rays = (*cub)->window_w;
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
		(*game)->ray->rotation_angle = 0;
	if (p->direction == 'E')
		(*game)->ray->rotation_angle = 180 * M_PI / 180;
}
