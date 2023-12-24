/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:21:39 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/24 13:12:06 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_player(t_game **cub)
{
	t_ray	*r;

	r = (*cub)->ray;
	r->rotation_angle += r->rotate_dir * r->rotation_speed;
}

int	move_player(t_game **cub)
{
	t_ray	*r;
	double	move_angle;
	double	move_step;
	double	new_x;
	double	new_y;

	if (!cub || !(*cub))
		return (0);
	r = (*cub)->ray;
	move_angle = r->rotation_angle;
	if (r->walk_dir == -1)
		move_angle = normalize_angle(move_angle + M_PI);
	else if (r->turn_dir == -1)
		move_angle = normalize_angle(move_angle - M_PI_2);
	else if (r->turn_dir == 1)
		move_angle = normalize_angle(move_angle + M_PI_2);
	move_step = (*cub)->size * 0.5;
	new_x = (*cub)->pos_x + cos(move_angle) * move_step;
	new_y = (*cub)->pos_y + sin(move_angle) * move_step;
	cast_ray(cub, -1, move_angle, 0);
	if (r->dis <= 32 || is_wall(cub, new_x, new_y))
		return (0);
	(*cub)->pos_x = new_x;
	(*cub)->pos_y = new_y;
	return (1);
}
