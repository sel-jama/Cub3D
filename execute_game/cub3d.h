/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:35:19 by sel-jama          #+#    #+#             */
/*   Updated: 2023/11/26 00:06:29 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <limits.h>
# include <stdio.h>

#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_FORWARD 126
#define KEY_BACKWARD 125
#define FOV 60 
//* (PI_M / 100)

typedef struct ray
{
    double angle;
    double hit_x;
    double hit_y;
    double hit_hx;
    double hit_hy;
    double hit_vx;
    double hit_vy;
    double xstep;
    double ystep;
    double move_step;
    double first_interx;
    double first_intery;
    double dis;
    double h_dis;
    double v_dis;
    int hit_is_v;
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
    int next_hx;
    int next_hy;
    int next_vx;
    int next_vy;
    int found_h_hit;
    int found_v_hit;
    double dis_proj_plane;
    double proj_wall_height;
}t_ray;

typedef struct game
{
    char **map;
    int rows;
    int cols;
    int size;
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
    t_ray *ray_array;
}t_game;

void    start_game(t_game *cub);
void error_ditected(const char* error);
void initializer(t_game **cub);
void cast_rays(t_game **cast);
double normalize_angle(double angle);
void init_ray_h(t_game **info);
void init_ray_v(t_game **info);
double get_distance(double x1, double x2, double y1, double y2);
void cast_ray(t_game **cast, int col_id);
int keypress_event(int keycode, t_game *cub);
int keyrelease(int keycode, t_game *cub);
int is_wall(t_game **cub, double x, double y);
void update_data(t_game **cub);
void put_wall(t_game **cub, int x, int y);
void put_floor(t_game **cub, int x, int y);
void render_map(t_game **cub);
void render_frame(t_game **cub);
void put_player(t_game **cub);

// void mlx_draw_line(void *mlx, void *win, int x0, int y0, int x1, int y1);


#endif