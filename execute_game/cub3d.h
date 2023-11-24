/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:35:19 by sel-jama          #+#    #+#             */
/*   Updated: 2023/11/24 14:29:15 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

#define KEY_LEFT 124
#define KEY_RIGHT 123
#define KEY_FORWARD 125
#define KEY_BACKWARD 126
#define FOV 60 
//* (PI_M / 100)

typedef struct game
{
    char **map;
    const int rows;
    const int cols;
    const int size;
    double pos_x;
    double pos_y;
    int rad;
    float width;
    float hight;
    void *mlx;
    void *window;
    int window_w;
    int window_h;
    t_ray *ray;
}t_game;

typedef struct ray
{
    double angle;
    double hit_x;
    double hit_y;
    double xstep;
    double ystep;
    double first_interx;
    double first_intery;
    double dis;
    int hit_v_or_h;
    int wall_hit_cont;
    int turn_dir;   //-1 if left +1 if right 0 if not updated
    int walk_dir;
    double rotation_angle;
    double move_speed; //walking speed of player
    double rotation_speed;
    double radius;
    int num_rays;
    int facing_down;
    int facing_up;
    int facing_right;
    int facing_left;
}t_ray;

void    start_game(t_game *cub);
void error_ditected(const char* error);
void initializer(t_game **cub);

#endif