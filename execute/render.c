/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:56:40 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/19 22:55:09 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1, int color)
{
    double deltax;
    double deltay;

    deltax = x1 - x0;
    deltay = y1 - y0;
    int pixls = sqrt((deltax * deltax) + (deltay * deltay));
    deltax /= pixls;
    deltay /= pixls;
    double pixl_x = x0;
    double pixl_y = y0;
    while (pixls)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, pixl_x, pixl_y, color);
        pixl_x += deltax;
        pixl_y += deltay;
        pixls--;
    }
}

// void render_3dprojection(t_game **cub)
// {
//     int i = 0;
//     t_ray *tmp;

//     tmp = (*cub)->ray;
//     mlx_clear_window((*cub)->mlx, (*cub)->window);
//     while (i < tmp->num_rays)
//     {
//         t_ray *r = &(*cub)->ray_array[i];
//         double ray_dis = r->dis;
//         // calculate the distance to the projection plane
//         // r->dis_proj_plane = ((*cub)->window_w / 2) / tan(FOV / 2);
        
//         // projection wall height
//         // r->proj_wall_height = ((*cub)->size / ray_dis) * r->dis_proj_plane;
        
//         // int wall_strip_h = (int)r->proj_wall_height;
//         // int wall_top_pxl = ((*cub)->window_w / 2) - (wall_strip_h / 2);
//         // if (wall_top_pxl < 0)
//         //     wall_top_pxl = 0;
//         // int wall_bottom_pxl = ((*cub)->window_h / 2) + (wall_strip_h / 2);
//         // if (wall_bottom_pxl < 0)
//         //     wall_bottom_pxl = (*cub)->window_h;

//         //render the wall from topPxl to bottomPxl
//         double line_h = (*cub)->window_h * (*cub)->size / ray_dis;
//         draw_vertical_line(cub, i, line_h);
//         // int y;
//         // y = wall_top_pxl;
//         // while (y < wall_bottom_pxl)
//         // {
//         //     colorBuff[((*cub)->window_w * y) + i] = 0xFF0000;
//         //     y++;
//         // }
//         // double proj_wall_w = 1;
//         // draw_rect_recursive((*cub)->mlx, (*cub)->window, i * proj_wall_w,
//         //     ((*cub)->window_h / 2) - (r->proj_wall_height / 2), proj_wall_w , r->proj_wall_height, 3, 0xFF0000);
//         i++;
//     }
// }

// Draw the wall segment vertically
void draw_vertical_line(t_game **cub, int x, int wall_height)
{
    t_game *game;
    int color2 = 0xCCCCCC;
    //int bits;
    //int size_line;
    //int endian;

    game = *cub;
    // char *ptr;
    // size_t color2;
    // game->img2 = mlx_xpm_file_to_image(game->mlx, "execute/photos_2022_5_17_fst_brick-wall-red-old-_1_.xpm", &game->j, &game->i);
    // game->addr = mlx_get_data_addr(game->img2, &game->bits_per_pixel, &game->line_length, &game->endian);
     
    int y_start = (game->window_h - wall_height) / 2;
    int y_end = y_start + wall_height;
    int y;
    int v;
    // int k;
    v = 0;
    //char  *dst;
   // int xgame = (game->j * (fmod(/*(x_hit + y_hit)*/ game->ray->hit_x + game->ray->hit_y, 64))) / 64;
    for (y = y_start; y < y_end; y++)
    {
    //    int ygame = (game->i * (y - y_start)) / wall_height;
      //  dst =  game->addr + ((ygame) * game->line_length + (xgame) * (game->bits_per_pixel / 8));
        //color2 = *(unsigned int*)dst;
        mlx_pixel_put(game->mlx, game->window, x, y, color2);
        //game->tmp++;
    }
}



void render_ray(t_game **cub, t_ray **r)
{
    t_ray *ray;

    ray = *r;
    draw_line((*cub)->mlx, (*cub)->window, MINIMAP_S * (*cub)->pos_x, MINIMAP_S *(*cub)->pos_y,
       MINIMAP_S *ray->hit_x,  MINIMAP_S * ray->hit_y, 0xCCCCCC);
}

int render_frame(t_game *cub)
{
    if (!update_player_pos(&cub))
        return (0);
    mlx_clear_window(cub->mlx, cub->window);
    // init_ray(&cub);
    // render_3dprojection(&cub);
    
    cast_rays(&cub);
    render_mini_board(&cub, cub->rows, cub->cols);
    put_player(&cub);
    // render_rays(&cub);
    return (0);
}

