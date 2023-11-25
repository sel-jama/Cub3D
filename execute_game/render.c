/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:56:40 by sel-jama          #+#    #+#             */
/*   Updated: 2023/11/26 00:28:31 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void put_wall(t_game **cub, int x, int y)
{
    void *img;
    int w;
    int h;

    img = mlx_xpm_file_to_image((*cub)->mlx, "../textures/wall.xpm", &w, &h);
    if (!img)
    {
        error_ditected("Wrong image ..");
        return ;
    }
    if (mlx_put_image_to_window((*cub)->mlx, (*cub)->window, img, x, y) == -1)
        error_ditected("Failed to put image to window");
}

void put_floor(t_game **cub, int x, int y)
{
    void *img;
    int w;
    int h;

    img = mlx_xpm_file_to_image((*cub)->mlx, "../textures/floor.xpm", &w, &h);
    if (!img)
    {
        error_ditected("Wrong image...");
        return ;
    }
    if (mlx_put_image_to_window((*cub)->mlx, (*cub)->window, img, x, y) == -1)
        error_ditected("Failed to put image to window");
}

void put_player(t_game **cub)
{
    // void *img;
    // int w;
    // int h;

    // img = mlx_xpm_file_to_image((*cub)->mlx, "../textures/player.xpm", &w, &h);
    // if (!img)
    // {
    //     error_ditected("Wrong image...");
    //     return ;
    // }
    // if (mlx_put_image_to_window((*cub)->mlx, (*cub)->window, img, (*cub)->pos_x, (*cub)->pos_y) == -1)
    //     error_ditected("Failed to put image to window");
    mlx_pixel_put((*cub)->mlx, (*cub)->window, (*cub)->pos_x, (*cub)->pos_y, 0xFF0000);
}


void render_map(t_game **cub)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    while (i < (*cub)->rows)
    {
        j = 0;
        while (j < (*cub)->cols)
        {
            x = j * (*cub)->size;
            y = i * (*cub)->size;
            if ((*cub)->map[i][j])
                put_wall(cub, x, y);
            else
                put_floor(cub, x, y);
            j++;
        }
        i++;
    }
}

void draw_line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1, int color)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = (float)dx / (float)steps;
    float yIncrement = (float)dy / (float)steps;

    float x = x0;
    float y = y0;

    for (int i = 0; i <= steps; i++)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, color);
        x += xIncrement;
        y += yIncrement;
    }
}

void render_ray(t_game **cub)
{
    draw_line((*cub)->mlx, (*cub)->window, (*cub)->pos_x, (*cub)->pos_y,
        (*cub)->pos_x + cos((*cub)->ray->angle)*30, (*cub)->pos_y + sin((*cub)->ray->angle)*30, 0xFF0000);
}

// void draw_rect_recursive(void *mlx, void *win, int x, int y, int width, int height, int depth, int color)
// {
//     if (depth <= 0) {
//         return;
//     }

//     // Draw the current rectangle
//     for (int i = 0; i < width; i++) {
//         mlx_pixel_put(mlx, win, x + i, y, color);              // Top side
//         mlx_pixel_put(mlx, win, x + i, y + height, color);     // Bottom side
//     }

//     for (int i = 0; i < height; i++) {
//         mlx_pixel_put(mlx, win, x, y + i, color);              // Left side
//         mlx_pixel_put(mlx, win, x + width, y + i, color);      // Right side
//     }

//     // Recursively draw smaller rectangles
//     draw_rect_recursive(mlx, win, x , y , width , height , depth - 1, color);
// }

// int main(void)
// {
//     t_vars vars;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, 500, 500, "Recursive Rectangles");

//     // Draw a red rectangle at position (50, 50) with width 100, height 80, and recursion depth 3
//     draw_rect_recursive(vars.mlx, vars.win, 50, 50, 100, 80, 3, 0xFF0000);  // 0xFF0000 is red in hexadecimal

//     mlx_loop(vars.mlx);

//     return 0;
// }


void render_3dprojection(t_game **cub)
{
    int i = 0;
    t_ray *r;

    r = (*cub)->ray;
    while (i < r->num_rays)
    {
        t_ray ray = (*cub)->ray_array[i];
        double ray_dis = ray.dis;
        //calculate the distance to the projection plane
        r->dis_proj_plane = ((*cub)->window_w / 2) / tan(FOV / 2);
        
        //projection wall height
        r->proj_wall_height = ((*cub)->size / ray_dis) * r->dis_proj_plane;
        
        double proj_wall_w = 1;
        draw_rect_recursive((*cub)->mlx, (*cub)->window, i * proj_wall_w,
            ((*cub)->window_h / 2) - (r->proj_wall_height / 2), proj_wall_w , r->proj_wall_height, 3, 0xFF0000);
        i++;
    }
}

void update(t_game **cub)
{
    // update player
    update_data(cub);
    cast_rays(cub);
}

void render_frame(t_game **cub)
{
    //update objects
    update(cub);

    render_3dprojection(cub);
    // render_map(cub);
    put_player(cub);
    render_ray(cub);
}