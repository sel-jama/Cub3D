/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:45:01 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/12 19:25:16 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void put_pixels_inblock(char content, t_game **cub, int x, int y)
{
    int color;
   
    color = 0x000000;
    int i = 0;
    while (i < (*cub)->size)
    {
        int j = 0;
        while (j < (*cub)->size)
        {
            if (content != '1')
                mlx_pixel_put((*cub)->mlx, (*cub)->window, x + i * MINIMAP_S, y + j * MINIMAP_S, color);
            else
                mlx_pixel_put((*cub)->mlx, (*cub)->window, x + i * MINIMAP_S, y + j * MINIMAP_S, 0xFFFFFF);
            // if (is_player(content))
            //     put_player(cub);
            j++;
        }
        i++;
    }
}

void	render_mini_board(t_game **game, int row, int col)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
    // mlx_clear_window((*game)->mlx, (*game)->window);
	while (row > 0)
	{
		j = 0;
		x = 0;
		while (col > 0)
		{
			put_pixels_inblock((*game)->path->map[i][j], game, MINIMAP_S * x, MINIMAP_S * y);
			x += (*game)->size;
			j++;
			col--;
		}
		col = (*game)->cols;
		i++;
		y += (*game)->size;
		row--;
	}
}

void put_player(t_game **cub)
{
    int radius = 2;
    int color = 0xFF0000;
    int i;
    int j;
    int x;
    int y;
    int flag = 0;

    // if ((*cub)->old_x || (*cub)->old_y)
    // {

    //     mlx_pixel_put((*cub)->mlx, (*cub)->window, (*cub)->old_x, (*cub)->old_y, 0xFFFFFF);
    //      draw_line((*cub)->mlx, (*cub)->window, (*cub)->old_x, (*cub)->old_y, 
    //                 (*cub)->old_x + cos((*cub)->ray->rotation_angle) * 30, (*cub)->old_y + sin((*cub)->ray->rotation_angle) * 30, 0xFFFFFF);
    // }
    for (i = -radius; i <= radius; i++)
    {
        for (j = -radius; j <= radius; j++)
        {
            // Check if the point (i, j) is inside the circle using the circle equation
            if (i * i + j * j <= radius * radius)
            {
                x = (*cub)->pos_x * MINIMAP_S + i;
                y = (*cub)->pos_y * MINIMAP_S + j;
    
                mlx_pixel_put((*cub)->mlx, (*cub)->window, x, y, color);
                if (!flag)
                {
                    flag = 1;
                    draw_line((*cub)->mlx, (*cub)->window, x, y,
                        x + cos((*cub)->ray->rotation_angle) * 15, y + sin((*cub)->ray->rotation_angle) * 15, color);
                }
            }
        }
    }
}