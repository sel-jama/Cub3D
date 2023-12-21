/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:21:39 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/21 21:07:26 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void turn_player(t_game **cub)
{
    t_ray   *r;

    r = (*cub)->ray;
    r->rotation_angle += r->rotate_dir * r->rotation_speed;
}

int move_player(t_game **cub)
{
    // Extract relevant information from t_game and t_ray structures
    double pos_x = (*cub)->pos_x;
    double pos_y = (*cub)->pos_y;
    t_ray *r = (*cub)->ray;

    // Adjust the movement angle based on directions
    double move_angle = r->rotation_angle;
    if (r->walk_dir == -1)
        move_angle = normalize_angle(move_angle + M_PI);
    else if (r->turn_dir == -1)
        move_angle = normalize_angle(move_angle - M_PI_2);
    else if (r->turn_dir == 1)
        move_angle = normalize_angle(move_angle + M_PI_2);

    // Calculate the new position
    double move_step = (*cub)->size * 0.25;
    double new_x = pos_x + cos(move_angle) * move_step;
    double new_y = pos_y + sin(move_angle) * move_step;
    cast_ray(cub, -1, move_angle);
    if (r->dis <= 16 || is_wall(cub, new_x, new_y))
        return 0;
    // No wall detected, update the player position
    (*cub)->pos_x = new_x;
    (*cub)->pos_y = new_y;
    return 1;
}
