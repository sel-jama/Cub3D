/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:56:48 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/26 13:46:14 by sel-jama         ###   ########.fr       */
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

void load_images2(t_game **cub)
{

	(*cub)->img1 = mlx_xpm_file_to_image((*cub)->mlx, (*cub)->path->no, &(*cub)->i1, &(*cub)->j1);
	if(!(*cub)->img1)
		ft_errors();
	(*cub)->addr = mlx_get_data_addr((*cub)->img1, &(*cub)->bits_per_pixel1, &(*cub)->line_length1, &(*cub)->endian1);
	if(!(*cub)->addr)
		ft_errors();
	(*cub)->img2 = mlx_xpm_file_to_image((*cub)->mlx, (*cub)->path->so, &(*cub)->i2, &(*cub)->j2);
	if(!(*cub)->img2)
		ft_errors();
	(*cub)->addr2 = mlx_get_data_addr((*cub)->img2, &(*cub)->bits_per_pixel2, &(*cub)->line_length2, &(*cub)->endian2);
	if(!(*cub)->addr2)
		ft_errors();
	(*cub)->img3 = mlx_xpm_file_to_image((*cub)->mlx, (*cub)->path->we, &(*cub)->i3, &(*cub)->j3);
	if(!(*cub)->img3)
		ft_errors();
	(*cub)->addr3 = mlx_get_data_addr((*cub)->img3, &(*cub)->bits_per_pixel3, &(*cub)->line_length3, &(*cub)->endian3);
	if(!(*cub)->addr3)
		ft_errors();
	(*cub)->img4 = mlx_xpm_file_to_image((*cub)->mlx, (*cub)->path->ea, &(*cub)->i4, &(*cub)->j4);
	if(!(*cub)->img4)
		ft_errors();
	(*cub)->addr4 = mlx_get_data_addr((*cub)->img4, &(*cub)->bits_per_pixel4, &(*cub)->line_length4, &(*cub)->endian4);
	if(!(*cub)->addr4)
		ft_errors();

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
