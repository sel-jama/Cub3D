/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:56:51 by sel-jama          #+#    #+#             */
/*   Updated: 2023/11/24 14:32:24 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//substract 30 degres form FOV
//start from 0
//while (col < 320) - cast a ray until a wall is hit - record intersection (x,y)

void cast_rays(t_game **cast)
{
    int ray_angle;
    int i;
    
    ray_angle = (*cast)->ray->rotation_angle - (FOV / 2);
    i = 0;
    while (i < (*cast)->ray->num_rays)
    {
        cast_ray(cast, i);
        ray_angle += FOV / (*cast)->ray->num_rays;
        i++;
    }
 }

double normalize_angle(double angle)
{
    // angle = floor(angle) % (2 * M_PI);
    if (angle < 0)
        angle = (2 * M_PI) + angle;
    return (angle);
}

 void cast_ray(t_game **cast, int col_id)
 {
    t_ray *ray;

    ray = (*cast)->ray;
    ray->angle = normalize_angle(ray->angle);
    ray->hit_x = 0;
    ray->hit_y = 0;
    ray->dis = 0;
    //check if ray is facing down
    if (ray->angle > 0 && ray->angle < M_PI)
        ray->facing_down = 1;
    if (!ray->facing_down)
        ray->facing_down = 1;
    if (ray->angle < 0.5 * M_PI || ray->angle > 1.5 * M_PI)
        ray->facing_right = 1;
    if (!ray->facing_right)
        ray->facing_left = 1;
    
    //Horizontal intersection
     //find the first intersection coordinates Ax and Ay (closest horizontal intersection coor)
     ray->first_intery = floor((*cast)->pos_y / (*cast)->size);
     
     ray->first_interx = (*cast)->pos_x + (ray->first_intery - (*cast)->pos_y) / tan(ray->angle);
 }