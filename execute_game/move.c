/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:56:44 by sel-jama          #+#    #+#             */
/*   Updated: 2023/11/23 14:39:52 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_hook(int keycode, t_game *cub)
{
	if (keycode == KEY_LEFT)
		look_left(&cub);
	else if (keycode == KEY_RIGHT)
		look_right(&cub);
	else if (keycode == 53)
		exit (0);
	return (0);
}

void    start_game(t_game *cub)
{
    cub->mlx = mlx_init();
    if (!cub->mlx)
        error_ditected("init failed");
    cub->window = mlx_new_window(cub->mlx, cub->window_w,
		cub->window_h, "Cub3D");
	if (!cub->window)
		error_ditected("Failed to open window");
	mlx_loop(cub->mlx);
}