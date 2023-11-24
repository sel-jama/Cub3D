/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:56:40 by sel-jama          #+#    #+#             */
/*   Updated: 2023/11/23 19:12:43 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void put_wall(t_game **cub, int x, int y)
{
    void *img;
    int w;
    int h;

    img = mlx_xpm_file_to_image((*cub)->mlx, "wall.xpm", &w, &h);
    if (mlx_put_image_to_window((*cub)->mlx, (*cub)->window, img, x, y) == -1)
        error_ditected("Failed to put image to window");
}

void render_map(t_game **cub){
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

void render_frame(t_game* cub){
    //update objects
    render_map(&cub);
    
}