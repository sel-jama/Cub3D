/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:56:51 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/21 21:15:53 by sel-jama         ###   ########.fr       */
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

double normalize_angle(double angle)
{
    angle = remainder(angle ,(2 * M_PI));
    if (angle < 0)
        angle = (2 * M_PI) + angle;
    return (angle);
}

void init_ray_h(t_ray *ray, double ray_angle)
{
    ray->angle = normalize_angle(ray_angle);
    ray->hit_hx = 0;
    ray->hit_hy = 0;
    ray->facing_down = 0;
    ray->facing_left = 0;
    ray->facing_up = 0;
    ray->facing_right = 0;
    ray->found_h_hit = 0;
    if (ray->angle > 0 && ray->angle < M_PI)
        ray->facing_down = 1;
    if (!ray->facing_down)
        ray->facing_up = 1;
    if (ray->angle < 0.5 * M_PI || ray->angle > 1.5 * M_PI)
        ray->facing_right = 1;
    if (!ray->facing_right)
        ray->facing_left = 1;
}

void init_ray_v(t_ray *ray)
{
    ray->found_v_hit = 0;
    ray->hit_vx = 0;
    ray->hit_vy = 0;
}

double get_distance(double x1, double y1, double x2, double y2)
{
    return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

int first_horz_inter(t_game **cub, t_ray *ray, double *dx, double *dy)
{
    *dy = floor((*cub)->pos_y / (*cub)->size) * (*cub)->size;
    if (ray->facing_down)
        *dy += (*cub)->size;
    if (ray->angle == 2 * M_PI || ray->angle == M_PI)
    {
        ray->found_h_hit = -1;
        return (0);
    }
    *dx = (*cub)->pos_x + (*dy - (*cub)->pos_y) / tan(ray->angle);
    return (1);
}

int first_vert_inter(t_game **cub, t_ray *ray, double *dx, double *dy)
{
    *dx = floor((*cub)->pos_x / (*cub)->size) * (*cub)->size;
    if (ray->facing_right)
        *dx += (*cub)->size;
    if (ray->angle == (1.5 * M_PI) || ray->angle == 0.5 * M_PI)
    {
        ray->found_v_hit = -1;
        return (0);
    }
    *dy = (*cub)->pos_y + (*dx - (*cub)->pos_x) * tan(ray->angle);
    return (1);
}

void calculate_horz_step(int size, t_ray *ray, double *x, double *y)
{
    double xstep;
    double ystep;

    ystep = size;
    if (ray->facing_up)
        ystep *= -1;
    
    xstep = size / tan(ray->angle);
    if (ray->facing_left && xstep > 0)
        xstep *= -1;
    if (ray->facing_right && xstep < 0)
        xstep *= -1;
    *x = xstep;
    *y = ystep;
}


void calculate_vert_step(int size, t_ray *ray, double *x, double *y)
{
    double xstep;
    double ystep;
        
    xstep = size;
    if (ray->facing_left)
        xstep *= -1;
    // else
    //     xstep += 0.0001;
    ystep = size * tan(ray->angle);
    if ((ray->facing_up && ystep > 0) || (ray->facing_down && ystep < 0))
        ystep *= -1;
    *x = xstep;
    *y = ystep;
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

void closest_distance(t_game **cast, t_ray *ray)
{
    double h_dis = INT_MAX;
    double v_dis = INT_MAX;

    if (ray->found_v_hit != -1 && ray->found_v_hit == 1)
        v_dis = get_distance((*cast)->pos_x, (*cast)->pos_y, ray->hit_vx, ray->hit_vy);
    if (ray->found_h_hit != -1 && ray->found_h_hit == 1)
        h_dis = get_distance((*cast)->pos_x, (*cast)->pos_y, ray->hit_hx, ray->hit_hy);

    if (h_dis < v_dis)
    {
        ray->hit_x = ray->hit_hx;
        ray->hit_y = ray->hit_hy;
        ray->dis = h_dis;
        ray->hit_is_v = 0;
    }
    else
    {
        ray->hit_x = ray->hit_vx;
        ray->hit_y = ray->hit_vy;
        ray->dis = v_dis;
        ray->hit_is_v = 1;
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
