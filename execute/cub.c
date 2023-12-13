/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:56:48 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/12 19:39:05 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char content)
{
	if (content == 'N' || content == 'S' ||
		content == 'W'|| content == 'E')
		return (1);
	return (0);
}

void get_player_pos(t_game **game, int row, int col)
{
	int	x;
	int	y;
	int s = (*game)->size;
	char **m = (*game)->path->map;

	y = 0;
	while (row > 0)
	{
		x = 0;
		while (col > 0)
		{
			if (is_player(m[y / s][x / s]))
    		{
        		(*game)->pos_x = x;
        		(*game)->pos_y = y;
				(*game)->direction = m[y / s][x / s];
				return ;
			}
			x += s;
			col--;
		}
		col = (*game)->cols;
		y += s;
		row--;
	}
}

void    start_game(t_game *cub)
{
    cub->mlx = mlx_init();
	get_player_pos(&cub, cub->rows, cub->cols);
	initializer(&cub);
    if (!cub->mlx)
        error_ditected("init failed");
    cub->window = mlx_new_window(cub->mlx, cub->window_w,
		cub->window_h, "Cub3D");
	if (!cub->window)
		error_ditected("Failed to open window");
	mlx_hook(cub->window, 2, 0, keypress_event, cub);
	mlx_hook(cub->window, 3, 0, keyrelease, cub);
	mlx_hook(cub->window, 17, 0, ft_exit, NULL);
	render_frame(cub);
	// mlx_loop_hook(cub->mlx, render_frame, cub);
	mlx_loop(cub->mlx);
}