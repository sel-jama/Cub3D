/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:56:51 by sel-jama          #+#    #+#             */
/*   Updated: 2023/11/26 00:08:44 by sel-jama         ###   ########.fr       */
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

void init_ray_h(t_game **info)
{
    // t_ray r;

    // (*info)->ray = &r;
    t_ray *ray = (*info)->ray;
    ray->angle = normalize_angle(ray->angle);
    ray->hit_hx = 0;
    ray->hit_hy = 0;
    ray->h_dis = INT_MAX;
    ray->facing_down = 0;
    ray->facing_left = 0;
    ray->facing_up = 0;
    ray->facing_right = 0;
    ray->found_h_hit = 0;
    ray->ystep = 1;
    ray->xstep = 1;
}

void init_ray_v(t_game **info)
{
    t_ray *ray;

    ray = (*info)->ray;
    ray->found_v_hit = 0;
    ray->hit_vx = 0;
    ray->hit_vy = 0;
    ray->ystep = 1;
    ray->xstep = 1;
    ray->v_dis = INT_MAX;
}

double get_distance(double x1, double x2, double y1, double y2)
{
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

 void cast_ray(t_game **cast, int col_id)
 {
    (void)col_id;
    init_ray_h(cast);
    t_ray *ray;
    ray = &(*cast)->ray_array[col_id];
    //check if ray is facing down
    if (ray->angle > 0 && ray->angle < M_PI)
        ray->facing_down = 1;
    if (!ray->facing_down)
        ray->facing_up = 1;
    if (ray->angle < 0.5 * M_PI || ray->angle > 1.5 * M_PI)
        ray->facing_right = 1;
    if (!ray->facing_right)
        ray->facing_left = 1;
    
    //Horizontal intersection
     //find the first intersection coordinates Ax and Ay (closest horizontal intersection coor)
    ray->first_intery = floor((*cast)->pos_y / (*cast)->size) * (*cast)->size;
    if (ray->facing_down)
        ray->first_intery += (*cast)->size;
    ray->first_interx = (*cast)->pos_x + (ray->first_intery - (*cast)->pos_y) / tan(ray->angle);
    //calculate xstep and ystep
    ray->ystep = (*cast)->size;
    if (ray->facing_up)
        ray->ystep *= -1;
    ray->xstep = (*cast)->size / tan(ray->angle);
    if (ray->facing_left && ray->xstep > 0)
        ray->xstep *= -1;
    if (ray->facing_right && ray->xstep < 0)
        ray->xstep *= -1;
    
    ray->next_hx = ray->first_interx;
    ray->next_hy = ray->first_intery;
    if (ray->facing_up)
        ray->next_hx--;
    //increment xstep and ystep until a wall is found
    while (ray->next_hx >= 0 && ray->next_hx <= (*cast)->window_w
        && ray->next_hy >= 0 && ray->next_hy <= (*cast)->window_h)
    {
        if (is_wall(cast, ray->next_hx, ray->next_hy))
        {
            ray->found_h_hit = 1;
            ray->hit_hx = ray->next_hx;
            ray->hit_hy = ray->next_hy;
            break ;
        }
        else
        {
            ray->next_hx += ray->xstep;
            ray->next_hy += ray->ystep;
        }
    }

    //Vertical intersection
     //find the first intersection coordinates Ax and Ay (closest virtical intersection coor)
     init_ray_v(cast);
    ray->first_interx = floor((*cast)->pos_x / (*cast)->size) * (*cast)->size;
    if (ray->facing_right)
        ray->first_interx += (*cast)->size;
    ray->first_intery = (*cast)->pos_y + (ray->first_interx - (*cast)->pos_x) * tan(ray->angle);
    //calculate xstep and ystep
    ray->xstep = (*cast)->size;
    if (ray->facing_left)
        ray->xstep *= -1;
    ray->ystep = (*cast)->size * tan(ray->angle);
    if (ray->facing_up && ray->ystep > 0)
        ray->ystep *= -1;
    if (ray->facing_down && ray->ystep < 0)
        ray->ystep *= -1;
    
    ray->next_vx = ray->first_interx;
    ray->next_vy = ray->first_intery;
    if (ray->facing_left)
        ray->next_vx--;
    //increment xstep and ystep until a wall is found
    while (ray->next_vx >= 0 && ray->next_vx <= (*cast)->window_w
        && ray->next_vy >= 0 && ray->next_vy <= (*cast)->window_h)
    {
        if (is_wall(cast, ray->next_vx, ray->next_vy))
        {
            ray->found_v_hit = 1;
            ray->hit_vx = ray->next_vx;
            ray->hit_vy = ray->next_vy;
            break ;
        } 
        else
        {
            ray->next_vx += ray->xstep;
            ray->next_vy += ray->ystep;
        }
    }

    //calculate hori and vert distance and choose the closest 
    if (ray->found_h_hit)
        ray->h_dis = get_distance((*cast)->pos_x, (*cast)->pos_y, ray->hit_hx, ray->hit_hy);
    if (ray->found_h_hit)
        ray->v_dis = get_distance((*cast)->pos_x, (*cast)->pos_y, ray->hit_vx, ray->hit_vy);
    
    if (ray->h_dis < ray->v_dis)
    {
        ray->hit_x = ray->hit_hx;
        ray->hit_y = ray->hit_hy;
        ray->dis = ray->h_dis;
        ray->hit_is_v = 0;
    }
    else
    {
        ray->hit_x = ray->hit_vx;
        ray->hit_y = ray->hit_vy;
        ray->dis = ray->v_dis;
        ray->hit_is_v = 1;
    }
    
 }