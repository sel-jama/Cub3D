/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:56:44 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/22 23:40:10 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(int keycode, t_game *param)
{
	(void)param;
	(void)keycode;
	exit(0);
}

int	keypress_event(int keycode, t_game *cub)
{
	if (keycode == KEY_W)
		cub->ray->walk_dir = 1;
	else if (keycode == KEY_S)
		cub->ray->walk_dir = -1;
	else if (keycode == KEY_A)
		cub->ray->turn_dir = -1;
	else if (keycode == KEY_D)
		cub->ray->turn_dir = 1;
	else if (keycode == KEY_LEFT)
		cub->ray->rotate_dir = -1;
	else if (keycode == KEY_RIGHT)
		cub->ray->rotate_dir = 1;
	else if (keycode == 53)
		exit(0);
	render_frame(cub);
	return (0);
}

int	keyrelease(int keycode, t_game *cub)
{
	if (keycode == KEY_W && cub->ray->walk_dir == 1)
		cub->ray->walk_dir = 0;
	if (keycode == KEY_S && cub->ray->walk_dir == -1)
		cub->ray->walk_dir = 0;
	if (keycode == KEY_A && cub->ray->turn_dir == -1)
		cub->ray->turn_dir = 0;
	if (keycode == KEY_D && cub->ray->turn_dir == 1)
		cub->ray->turn_dir = 0;
	if (keycode == KEY_LEFT && cub->ray->rotate_dir <= 1)
		cub->ray->rotate_dir = 0;
	if (keycode == KEY_RIGHT && cub->ray->rotate_dir >= -1)
		cub->ray->rotate_dir = 0;
	return (0);
}

int	is_wall(t_game **cub, double x, double y)
{
	int	map_x;
	int	map_y;

	if (x < 0 || x > (*cub)->window_w || y < 0 || y > (*cub)->window_h)
		return (1);
	map_x = floor(x) / (*cub)->size;
	map_y = floor(y) / (*cub)->size;
	if (map_y >= (*cub)->rows || map_x >= (*cub)->cols)
		return (1);
	if ((*cub)->path->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

int	update_player_pos(t_game **cub)
{
	int		valid_move;
	t_ray	*ray;

	valid_move = 1;
	ray = (*cub)->ray;
	if (ray->rotate_dir == -1 || ray->rotate_dir == 1)
		turn_player(cub);
	if (ray->walk_dir || ray->turn_dir)
		valid_move = move_player(cub);
	return (valid_move);
}
