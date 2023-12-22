/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:56:51 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/22 07:10:57 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void cast_rays(t_game **cast)
{
    double ray_angle;
    int i;
    double inc_angle;
    
    ray_angle = (*cast)->ray->rotation_angle - (FOV / 2);
    inc_angle = FOV / (*cast)->window_w;
    i = 0;
    while (i < (*cast)->ray->num_rays)
    {
        cast_ray(cast, i, ray_angle);
        ray_angle += inc_angle;
        i++;
    }
}


void hori_hit_point(t_game **cast, t_ray *ray)
{
    double xstep;
    double ystep;
    double delta_x;
    double delta_y;
    double y_to_check;

    if (!first_horz_inter(cast, ray, &delta_x, &delta_y))
        return ;
    calculate_horz_step((*cast)->size, ray, &xstep, &ystep);
    while (delta_x >= 0 && delta_x <= (*cast)->window_w &&
           delta_y >= 0 && delta_y <= (*cast)->window_h)
    {
        y_to_check = delta_y;
        if (ray->facing_up)
            y_to_check--;
        if (is_wall(cast, delta_x, y_to_check))
        {
            ray->found_h_hit = 1;
            ray->hit_hx = delta_x;
            ray->hit_hy = delta_y;
            break;
        }
        delta_x += xstep;
        delta_y += ystep;
    }
}

void vert_hit_point(t_game **cast, t_ray *ray)
{
    double delta_x;
    double delta_y;
    double xstep;
    double ystep;
    double x_to_check;
    
    if (!first_vert_inter(cast, ray, &delta_x, &delta_y))
        return ;
    calculate_vert_step((*cast)->size, ray, &xstep, &ystep);
    while (delta_x >= 0 && delta_x <= (*cast)->window_w &&
           delta_y >= 0 && delta_y <= (*cast)->window_h)
    {
        x_to_check = delta_x;
        if (ray->facing_left)
            x_to_check--;
        if (is_wall(cast, x_to_check , delta_y))
        {
            ray->found_v_hit = 1;
            ray->hit_vx = delta_x;
            ray->hit_vy = delta_y;
            break;
        }
        delta_x += xstep;
        delta_y += ystep;
    }
}

// // process of casting rays from the player's viewpoint to determine what is visible in the scene
void cast_ray(t_game **cast, int col_id, double ray_angle)
{
    t_ray *ray;
    double line_h;
    
    ray = (*cast)->ray;
    init_ray_h(ray, ray_angle);
    hori_hit_point(cast, ray);
    init_ray_v(ray);
    vert_hit_point(cast, ray);
    closest_distance(cast, ray);
    if (col_id > 0)
    {
        //fix fisheye
        ray->dis = ray->dis * cos(ray->angle - ray->rotation_angle);
       line_h = (*cast)->window_h * (*cast)->size / ray->dis;
        draw_vertical_line(cast, col_id, line_h);
        // render_ray(cast, &ray);
    }
    
}
