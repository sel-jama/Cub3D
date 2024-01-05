/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_needs                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:44:17 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/05 18:44:55 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	load_images(t_game **cub)
{
	t_game	*tmp;

	tmp = *cub;
	if (open(tmp->path->no, O_RDONLY) == -1)
		ft_errors();
	if (open(tmp->path->so, O_RDONLY) == -1)
		ft_errors();
	if (open(tmp->path->we, O_RDONLY) == -1)
		ft_errors();
	if (open(tmp->path->ea, O_RDONLY) == -1)
		ft_errors();
	load_images2(cub);
}
