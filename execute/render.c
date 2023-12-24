/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:56:40 by sel-jama          #+#    #+#             */
/*   Updated: 2023/12/24 07:02:59 by sel-jama         ###   ########.fr       */
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
