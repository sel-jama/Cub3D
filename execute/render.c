/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:56:40 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/26 13:45:10 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_frame(t_game *cub)
{
	if (!update_player_pos(&cub))
		return (0);
	mlx_clear_window(cub->mlx, cub->window);
	cast_rays(&cub);
	return (0);
}
void	clean_up(t_game **param)
{
	int	i;
	char	**map;

	i = 0;
	map = (*param)->path->map;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	map = NULL;
	// mlx_destroy_window((*param)->mlx, (*param)->window);
}