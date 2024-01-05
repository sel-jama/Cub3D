/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:56:48 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/05 18:43:33 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char content)
{
	if (content == 'N' || content == 'S'
		|| content == 'W' || content == 'E')
		return (1);
	return (0);
}

int	recored_pos(t_game **game, int x, int y, char dir)
{
	t_game	*g;

	g = *game;
	g->pos_x = x + 0.5;
	g->pos_y = y + 0.5;
	g->direction = dir;
	return (1);
}

int	get_player_pos(t_game **game, int row, int col, int a)
{
	int		x;
	int		y;
	int		b;
	int		s;
	char	**m;

	y = 0;
	b = 0;
	m = (*game)->path->map;
	s = (*game)->size;
	while (row-- > 0)
	{
		x = 0;
		while (m[y / s][x / s])
		{
			a = y / s;
			b = x / s;
			if (is_player(m[a][b]))
				return (recored_pos(game, x, y, m[a][b]));
			x += s;
		}
		col = (*game)->cols;
		y += s;
	}
	return (0);
}

void	start_game(t_game *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		error_ditected("Initializing mlx failed");
	if (!get_player_pos(&cub, cub->rows, cub->cols, 0))
		error_ditected("Player not found");
	initializer(&cub);
	cub->window = mlx_new_window(cub->mlx, SCREEN_W,
			SCREEN_H, "Cub3D");
	load_images(&cub);
	if (!cub->window)
		error_ditected("Failed to open window");
	mlx_hook(cub->window, 2, 0, keypress_event, cub);
	mlx_hook(cub->window, 3, 0, keyrelease, cub);
	mlx_hook(cub->window, 17, 0, ft_exit, cub);
	render_frame(cub);
	mlx_loop(cub->mlx);
}
