/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:45:14 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/21 21:32:13 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void initializer(t_game **cub)
{
	t_game *init;

    init_dir(cub);
	init_ray(cub);
	init = *cub;
	init->window_w = init->cols * init->size;
	init->window_h = init->rows * init->size;
	// init->window_w = 32 * init->size;
	// init->window_h = 16 * init->size;
	// init->old_x = 0;
	// init->old_y = 0;
	init->addr = NULL;
	init->bits_per_pixel = 0;
	init->endian = 0;
	init->tmp = 0;
	init->img2 = NULL;
	init->line_length = 0;
	init->i = 0;
	init->tmp2 = 0;
	init->j = 0;
	// init->ray->turn_dir = 0;
	// init->ray->walk_dir = 0;
	// init->ray->rotation_angle = M_PI / 2;
	// init->ray->rotation_speed = 45 * (M_PI / 180);
	// init->ray->radius = 3.0;
	// init->ray->move_speed = 15;
	// init->ray->move_step = 0;
	init->ray->num_rays = init->window_w ;
	// (*cub)->ray_array = (t_ray*)malloc(sizeof(t_ray) * init->ray->num_rays);
	// for (int i = 0; i < init->ray->num_rays; i++)
	// 	init_rayarray(cub ,i);
}

void init_ray(t_game **cub)
{
	t_ray *init;

	init = (*cub)->ray;
	init->turn_dir = 0;
	init->walk_dir = 0;
	init->rotation_speed = 5 * M_PI / 180;
	init->num_rays = (*cub)->window_w;
	init->rotate_dir = 0;
}

void init_dir(t_game **game)
{
	t_game *p;

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