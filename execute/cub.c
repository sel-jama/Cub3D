/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:56:48 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/05 17:53:30 by yboucha          ###   ########.fr       */
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

    (void)col;
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

void	load_address(t_game **c)
{
	(*c)->addr = mlx_get_data_addr((*c)->img1, &(*c)->bits_per_pixel1,
			&(*c)->line_length1, &(*c)->endian1);
	if (!(*c)->addr)
		ft_errors();
	(*c)->addr2 = mlx_get_data_addr((*c)->img2, &(*c)->bits_per_pixel2,
			&(*c)->line_length2, &(*c)->endian2);
	if (!(*c)->addr2)
		ft_errors();
	(*c)->addr3 = mlx_get_data_addr((*c)->img3, &(*c)->bits_per_pixel3,
			&(*c)->line_length3, &(*c)->endian3);
	if (!(*c)->addr3)
		ft_errors();
	(*c)->addr4 = mlx_get_data_addr((*c)->img4, &(*c)->bits_per_pixel4,
			&(*c)->line_length4, &(*c)->endian4);
	if (!(*c)->addr4)
		ft_errors();
}

void	load_images2(t_game **c)
{
	t_path	*p;

	p = (*c)->path;
	(*c)->img1 = mlx_xpm_file_to_image((*c)->mlx, p->no, &(*c)->i1, &(*c)->j1);
	if (!(*c)->img1)
		ft_errors();
	(*c)->img2 = mlx_xpm_file_to_image((*c)->mlx, p->so, &(*c)->i2, &(*c)->j2);
	if (!(*c)->img2)
		ft_errors();
	(*c)->img3 = mlx_xpm_file_to_image((*c)->mlx, p->we, &(*c)->i3, &(*c)->j3);
	if (!(*c)->img3)
		ft_errors();
	(*c)->img4 = mlx_xpm_file_to_image((*c)->mlx, p->ea, &(*c)->i4, &(*c)->j4);
	if (!(*c)->img4)
		ft_errors();
	load_address(c);
}

void load_images(t_game **cub)
{
	t_game *tmp;

	tmp = *cub;
	if(open(tmp->path->no, O_RDONLY) == -1)
		ft_errors();
	if(open(tmp->path->so, O_RDONLY) == -1)
		ft_errors();
	if(open(tmp->path->we, O_RDONLY) == -1)
		ft_errors();
	if(open(tmp->path->ea, O_RDONLY) == -1)
		ft_errors();
	load_images2(cub);
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
