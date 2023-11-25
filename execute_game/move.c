/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:56:44 by sel-jama          #+#    #+#             */
/*   Updated: 2023/11/26 00:09:36 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	ft_key_hook(int keycode, t_game *cub)
// {
// 	if (keycode == KEY_LEFT)
// 		look_left(&cub);
// 	else if (keycode == KEY_RIGHT)
// 		look_right(&cub);
// 	else if (keycode == 53)
// 		exit (0);
// 	return (0);
// }

void initializer(t_game **cub)
{
	t_game *init;

	init = *cub;
	init->window_w = init->cols * init->size;
	init->window_h = init->rows* init->size;
	(*cub)->pos_x = init->window_w / 2;
	(*cub)->pos_y = init->window_h / 2;
	init->ray->turn_dir = 0;
	init->ray->walk_dir = 0;
	init->ray->rotation_angle = M_PI / 2;
	init->ray->rotation_speed = 2 * (M_PI / 180);
	init->ray->radius = 3.0;
	init->ray->move_speed = 3.0;
	init->ray->move_step = 0;
	init->ray->num_rays = init->window_w;
}

void init_ray(t_game **cub, int i)
{
	t_game *init;

	init = *cub;
	init->ray_array[i].turn_dir = 0;
	init->ray_array[i].walk_dir = 0;
	init->ray_array[i].rotation_angle = M_PI / 2;
	init->ray_array[i].rotation_speed = 2 * (M_PI / 180);
	init->ray_array[i].radius = 3.0;
	init->ray_array[i].move_speed = 3.0;
	init->ray_array[i].move_step = 0;
	init->ray_array[i].num_rays = init->window_w;
}

int keypress_event(int keycode, t_game *cub)
{
	if (keycode == KEY_FORWARD)
		(cub)->ray->walk_dir = -1;
	else if (keycode == KEY_BACKWARD)
		(cub)->ray->walk_dir = 1;
	else if (keycode == KEY_RIGHT)
		(cub)->ray->turn_dir = -1;
	else if (keycode == KEY_LEFT)
		(cub)->ray->turn_dir = 1;
	render_frame(&cub);
	return (0);
}

int keyrelease(int keycode, t_game *cub)
{
	if (keycode == KEY_FORWARD)
		(cub)->ray->walk_dir = 0;
	else if (keycode == KEY_BACKWARD)
		(cub)->ray->walk_dir = 0;
	else if (keycode == KEY_RIGHT)
		(cub)->ray->turn_dir = 0;
	else if (keycode == KEY_LEFT)
		(cub)->ray->turn_dir = 0;
	return (0);
}

int is_wall(t_game **cub, double x, double y)
{
	if (x < 0 || x > (*cub)->window_w || y < 0 || y > (*cub)->window_h)
		return (1);
	if ((*cub)->map[(int)y / (*cub)->size][(int)x / (*cub)->size])
		return (1);
	return (0);
}

void update_data(t_game **cub)
{
	//update player's position based on turn and wald dir
	t_ray *p;
	double new_x;
	double new_y;
	
	p = (*cub)->ray;
	p->rotation_angle += p->turn_dir * p->rotation_speed;
	p->move_step = p->walk_dir * p->move_speed;
	new_x = (*cub)->pos_x + cos(p->rotation_angle) * p->move_step;
	new_y = (*cub)->pos_y + sin(p->rotation_angle) * p->move_step;
	if (!is_wall(cub, new_x, new_y))
	{
		(*cub)->pos_x = new_x;
		(*cub)->pos_y = new_y;
	}
	printf("%f  %f\n", new_x, new_y);
	printf("%f  %f\n", (*cub)->pos_x, (*cub)->pos_y);
}

void    start_game(t_game *cub)
{
    cub->mlx = mlx_init();
	initializer(&cub);
    if (!cub->mlx)
        error_ditected("init failed");
    cub->window = mlx_new_window(cub->mlx, cub->window_w,
		cub->window_h, "Cub3D");
	if (!cub->window)
		error_ditected("Failed to open window");
	cub->ray_array = malloc(sizeof(t_ray) * cub->ray->num_rays);
	for (int i = 0; i < cub->ray->num_rays; i++)
		init_ray(&cub ,i);
	render_frame(&cub);
	mlx_hook(cub->window, 2, 0, keypress_event, cub);
	mlx_hook(cub->window, 3, 0, keyrelease, cub);
	// mlx_hook(cub->window, 17, 0, exit, NULL);
	mlx_loop(cub->mlx);
}
