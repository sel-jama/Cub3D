/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:35:19 by sel-jama          #+#    #+#             */
/*   Updated: 2023/11/22 13:25:39 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <mlx.h>

#define KEY_LEFT 124
#define KEY_RIGHT 123

typedef struct s_game
{
    int rows;
    int cols;
    int pos_x;
    int pos_y;
    float width;
    float hight;
    void *mlx;
    void *window;
}t_game;

typedef struct s_ray
{
    float angle;
    float hit_x;
    float hit_y;
    float dis;
    int hit_v_or_h;
    int wall_hit_cont;
    
}t_ray;



#endif