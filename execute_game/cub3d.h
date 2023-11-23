/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:35:19 by sel-jama          #+#    #+#             */
/*   Updated: 2023/11/23 14:59:44 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <mlx.h>

#define KEY_LEFT 124
#define KEY_RIGHT 123

typedef struct game
{
    char **map;
    const int rows;
    const int cols;
    const int size;
    int pos_x;
    int pos_y;
    int rad;
    float width;
    float hight;
    void *mlx;
    void *window;
    int window_w;
    int window_h;
}t_game;

typedef struct ray
{
    float angle;
    float hit_x;
    float hit_y;
    float dis;
    int hit_v_or_h;
    int wall_hit_cont;
    
}t_ray;

void    start_game(t_game *cub);
void error_ditected(const char* error);

#endif