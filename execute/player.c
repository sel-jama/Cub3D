/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:21:39 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/13 23:08:26 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int turn_player(t_game **cub)
{
    t_ray   *r;

    r = (*cub)->ray;
    r->rotation_angle += r->rotate_dir * r->rotation_speed;
//    double angle = r->rotation_angle;
//     double cos_angle = cos(angle);
//     double sin_angle = sin(angle);
//     double new_x = cos_angle;
//     double new_y = sin_angle;

//     r->xdir = new_x;
//     r->ydir = new_y;
    // double xsaver = r->xplane;
    // r->xplane = r->xplane * cos(r->rotation_speed) - r->yplane * sin(r->rotation_speed);
    // r->yplane = xsaver * sin(r->rotation_speed) + r->yplane * cos(r->rotation_speed);

    // (*cub)->move_step = (*cub)->walk_dir * (*cub)->move_speed;
	// (*cub)->pos_x += cos((*cub)->ray->rotation_angle) * (*cub)->ray->move_step;
	// (*cub)->pos_y += sin((*cub)->ray->rotation_angle) * (*cub)->ray->move_step;
    return (1);
}

void move_player(t_game **cub)
{
    double move_step;
    double new_x;
    double new_y;
    double move_angle;

    move_angle = (*cub)->ray->rotation_angle;
    if ((*cub)->ray->walk_dir == 1)
        move_angle = normalize_angle(move_angle);
    else if ((*cub)->ray->walk_dir == -1)
        move_angle = normalize_angle(move_angle + M_PI);
    else if ((*cub)->ray->turn_dir == -1)
        move_angle = normalize_angle(move_angle - M_PI_2);
    else if ((*cub)->ray->turn_dir == 1)
        move_angle = normalize_angle(move_angle + M_PI_2);
    move_step = (*cub)->ray->move_speed;
    new_x = (*cub)->pos_x + cos(move_angle) * move_step;
    new_y = (*cub)->pos_y + sin(move_angle) * move_step;
    if (is_wall(cub, new_x, new_y))
        return ;
    (*cub)->pos_x = new_x;
    (*cub)->pos_y = new_y;
}