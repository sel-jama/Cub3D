/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboucha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 05:52:37 by yboucha           #+#    #+#             */
/*   Updated: 2023/12/24 05:52:43 by yboucha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute/cub3d.h"

int	is_rounded(char **ptr, int i, int j)
{
	if ((ptr[i - 1]) && ((ptr[i - 1][j] == 32 || ptr[i - 1][j] == 9)
			|| ((ptr[i][j + 1] == 32 || ptr[i][j + 1] == 9))))
		return (2);
	if (ptr[i + 1] && ((ptr[i + 1][j] == 32 || ptr[i + 1][j] == 9)
			|| (!ptr[i][j - 1] || (ptr[i][j - 1] == 32 || ptr[i][j - 1] == 9))))
		return (2);
	if (ptr[i - 1][j] == '1' && ptr[i][j + 1] == '1'
			&& ptr[i][j - 1] == 1 && ptr[i + 1][j] == 1)
		return (2);
	if (!ptr[i + 1][j])
		return (2);
	return (1);
}

void	check_double(char **ptr, int i, int j)
{
	char	c;

	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			c = ptr[i][j];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
				ft_errors();
			j++;
		}
		i++;
	}
}

void	check_map3(int i, int n, char c)
{
	if ((i == n || i == 0) && (c != 32 && c != 9 && c != '\n' && c != '1'))
		ft_errors();
	if ((i != 0 && i != n) && (c != '1' && c != '0'
			&& c != 'N' && c != 'S' && c != 'W' && c != 'E'
			&& c != 32 && c != 9 && c != '\n'))
		ft_errors();
}
