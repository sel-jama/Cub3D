/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:19:27 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/12 19:31:56 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	move_forward(t_game **cub)
// {
// 	double	new_x;
// 	double	new_y;

// 	// (*cub)->ray->rotation_angle += (*cub)->ray->walk_dir * (*cub)->ray->rotation_speed;
// 	new_x = (*cub)->pos_x + (*cub)->ray->xdir * (*cub)->ray->move_speed;
// 	new_y = (*cub)->pos_y + (*cub)->ray->ydir * (*cub)->ray->move_speed;
// 	if (is_wall(cub, new_x, new_y))
//         return (0);
// 	(*cub old_x = (*cub)->pos_x;
// 	(*cub)->old_y = (*cub)->pos_y;
//     (*cub)->pos_x = new_x;
//     (*cub)->pos_y = new_y;
//     return (1);
// }

// int	move_backward(t_game **cub)
// {
// 	double	new_x;
// 	double	new_y;

// 	// (*cub)->ray->rotation_angle += (*cub)->ray->walk_dir * (*cub)->ray->rotation_speed;
// 	new_x = (*cub)->pos_x - (*cub)->ray->xdir * (*cub)->ray->move_speed;
// 	new_y = (*cub)->pos_y - (*cub)->ray->ydir * (*cub)->ray->move_speed;
// 	if (is_wall(cub, new_x, new_y))
//         return (0);
// 	(*cub)->old_x = (*cub)->pos_x;
// 	(*cub)->old_y = (*cub)->pos_y;
//     (*cub)->pos_x = new_x;
//     (*cub)->pos_y = new_y;
//     return (1);
// }

// int	move_left(t_game **cub)
// {
// 	double	new_x;
// 	double	new_y;

// 	// (*cub)->ray->rotation_angle += (*cub)->ray->turn_dir * (*cub)->ray->rotation_speed;
// 	new_x = (*cub)->pos_x + (*cub)->ray->ydir * (*cub)->ray->move_speed;
// 	new_y = (*cub)->pos_y - (*cub)->ray->xdir * (*cub)->ray->move_speed;
// 	if (is_wall(cub, new_x, new_y))
//         return (0);
// 	(*cub)->old_x = (*cub)->pos_x;
// 	(*cub)->old_y = (*cub)->pos_y;
//     (*cub)->pos_x = new_x;
//     (*cub)->pos_y = new_y;
//     return (1);
// }

// int	move_right(t_game **cub)
// {
// 	double	new_x;
// 	double	new_y;

// 	// (*cub)->ray->rotation_angle += (*cub)->ray->turn_dir * (*cub)->ray->rotation_speed;
// 	new_x = (*cub)->pos_x - (*cub)->ray->ydir * (*cub)->ray->move_speed;
// 	new_y = (*cub)->pos_y + (*cub)->ray->xdir * (*cub)->ray->move_speed;
// 	if (is_wall(cub, new_x, new_y))
//         return (0);
// 	(*cub)->old_x = (*cub)->pos_x;
// 	(*cub)->old_y = (*cub)->pos_y;
//     (*cub)->pos_x = new_x;
//     (*cub)->pos_y = new_y;
//     return (1);
// }