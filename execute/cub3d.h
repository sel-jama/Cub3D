/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:35:19 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/22 23:46:09 by sel-jama         ###   ########.fr       */
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
# include <stdint.h>
# include <float.h>
# include "../parse/Cube.h"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define FOV 60 * M_PI / 180
# define MINIMAP_S 1
# define SCREEN_W 900
# define SCREEN_H 600

typedef struct ray
{
	double angle;
	double hit_x;
	double hit_y;
	double hit_hx;
	double hit_hy;
	double hit_vx;
	double hit_vy;
	double move_step;
	double dis;
	double h_dis;
	double v_dis;
	int hit_is_v;
	int turn_dir;   //-1 if left +1 if right 0 if not updated
	int walk_dir;
	double rotation_angle;
	double move_speed; //walking speed of player
	double rotation_speed;
	int num_rays;
	int facing_down;
	int facing_up;
	int facing_right;
	int facing_left;
	int found_h_hit;
	int found_v_hit;
	int rotate_dir;
	double p_dis;
}t_ray;

typedef struct game
{
	int rows;
	int cols;
	int size;
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
	t_path *path;
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
int render_frame(t_game *cub);
void put_player(t_game **cub);
int update_player_pos(t_game **cub);
void	render_mini_board(t_game **game, int row, int col);
void init_dir(t_game **game);
void turn_player(t_game **cub);
void draw_vertical_line(t_game **cub, int x, int wall_height);
int move_player(t_game **cub);
int	is_player(char content);
int ft_exit(int keycode, t_game *param);
void render_ray(t_game **cub, t_ray **r);
void closest_distance(t_game **cast, t_ray *ray);
int first_horz_inter(t_game **cub, t_ray *ray, double *dx, double *dy);
int first_vert_inter(t_game **cub, t_ray *ray, double *dx, double *dy);
void calculate_horz_step(int size, t_ray *ray, double *x, double *y);
void calculate_vert_step(int size, t_ray *ray, double *x, double *y);
void init_ray(t_game **cub);

void draw_line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1, int color);

#endif
