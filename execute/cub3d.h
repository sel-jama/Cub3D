/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:35:19 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/19 22:51:23 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
#include <stdint.h>
#include <float.h>
# include "../parse/Cube.h"

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define FOV 60 * M_PI / 180
#define TIME_LENGTH (1000 / 30)
#define MINIMAP_S 0.25
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
    // double xstep;
    // double ystep;
    double move_step;
    
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
    // double radius;
    int num_rays;
    int facing_down;
    int facing_up;
    int facing_right;
    int facing_left;
    // int xdir;
    // int ydir;
    int next_hx;
    int next_hy;
    int next_vx;
    int next_vy;
    int found_h_hit;
    int found_v_hit;
    double dis_proj_plane;
    double proj_wall_height;
    int rotate_dir;
    int camera_x;
    double xplane;
    double yplane;
    int mid;
}t_ray;

typedef struct game
{
    int rows;
    int cols;
    int size;
    int updated;
    // double old_x;
    // double old_y;
    double pos_x;
    double pos_y;
    int rad;
    int endian ;
    int bits_per_pixel;
    int line_length; 
    int i;
    int j;
    char* img2 ;
    char* addr;
    int tmp;
    int tmp2;
    double width;
    double hight;
    void *mlx;
    void *window;
    void *img;
    int window_w;
    int window_h;
    char direction;
    t_ray *ray;
    // t_ray *ray_array;
    t_path *path;
    double first_interx;
    double first_intery;
    // double xstep;
    // double ystep;
    // uint32_t* color_buff;
}t_game;

void    start_game(t_game *cub);
void error_ditected(const char* error);
void initializer(t_game **cub);
void cast_rays(t_game **cast);
double normalize_angle(double angle);
void init_ray_h(t_ray *ray, double ray_angle);
void init_ray_v(t_ray *ray);
double get_distance(double x1, double x2, double y1, double y2);
 void cast_ray(t_game **cast, int col_id, double ray_angle);
int keypress_event(int keycode, t_game *cub);
int keyrelease(int keycode, t_game *cub);
int is_wall(t_game **cub, double x, double y);
void put_wall(t_game **cub, int x, int y);
void put_floor(t_game **cub, int x, int y);
void render_map(t_game **cub);
int render_frame(t_game *cub);
void put_player(t_game **cub);
int	move_forward(t_game **cub);
int	move_backward(t_game **cub);
int	move_left(t_game **cub);
int	move_right(t_game **cub);
int update_player_pos(t_game **cub);
void	image_renderer(char map_case, int x, int y, t_game **s);
void	render_mini_board(t_game **game, int row, int col);
void init_dir(t_game **game);
void init_rayarray(t_game **cub, int i);
void init_ray(t_game **cub);
int turn_player(t_game **cub);
void draw_walls(t_game **cub, int x, double wall_height);
void draw_vertical_line(t_game **cub, int x, int wall_height);
void update_ray(t_game **cub);
int move_player(t_game **cub);
int	is_player(char content);
int ft_exit(int keycode, t_game *param);
void render_ray(t_game **cub, t_ray **r);

void draw_line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1, int color);

#endif