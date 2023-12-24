/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_funs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboucha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:46:35 by yboucha           #+#    #+#             */
/*   Updated: 2023/12/24 00:06:26 by yboucha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>

void	load_map(int n, t_path **load)
{
	t_path	*load_2;

	load_2 = *load;
	load_2->map = (char **)malloc((sizeof(char *)) * (n + 1));
}

int	empty_line(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '0' || ptr[i] == '1' || ptr[i] == 'N'
			|| ptr[i] == 'S' || ptr[i] == 'W' || ptr[i] == 'E')
			return (1);
		i++;
	}
	return (0);
}

int	parametere_map2(char *ptr, t_path **load, char *str, int i)
{
	if ((ptr[i] == 'F' || ptr[i] == 'C'))
	{
		if ((ptr[i + 1] == 9 || ptr[i + 1] == 32) && ptr[i + 2])
		{
			str = ft_strtrim(ptr + (i + 2), "     ");
			if (ptr[i] == 'F')
				ptr = ft_strjoin("F ", str);
			else
				ptr = ft_strjoin("C ", str);
			load_identifier(ptr, 2, &(*load));
			return (1);
		}
	}
	if (ptr[i] == 'N' && ptr[i + 1] && ptr[i + 1] == 'O')
	{
		if ((ptr[i + 2] == 9 || ptr[i + 2] == 32) && ptr[i + 3])
		{
			str = ft_strtrim(ptr + 3, " ");
			ptr = ft_strjoin("NO ", str);
			load_identifier(ptr, 3, &(*load));
			return (1);
		}
	}
	return (0);
}

int	parametere_map3(char *ptr, t_path **load, char *str, int i)
{
	if (ptr[i] == 'S' && ptr[i + 1] && ptr[i + 1] == 'O')
	{
		if ((ptr[i + 2] == 9 || ptr[i + 2] == 32) && ptr[i + 3])
		{
			str = ft_strtrim(ptr + 3, " ");
			ptr = ft_strjoin("SO ", str);
			load_identifier(ptr, 3, &(*load));
			return (1);
		}
	}
	else if (ptr[i] == 'W' && ptr[i + 1] && ptr[i + 1] == 'E')
	{
		if ((ptr[i + 2] == 9 || ptr[i + 2] == 32) && ptr[i + 3])
		{
			str = ft_strtrim(ptr + 3, " ");
			ptr = ft_strjoin("WE ", str);
			load_identifier(ptr, 3, &(*load));
			return (1);
		}
	}
	return (0);
}

int	parametre_map(char *ptr, t_path **load_2)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (ptr[i])
	{
		if (parametere_map2(ptr, load_2, str, i) == 1)
			return (1);
		if (parametere_map3(ptr, load_2, str, i) == 1)
			return (1);
		if (ptr[i] == 'E' && ptr[i + 1] && ptr[i + 1] == 'A')
		{
			if ((ptr[i + 2] == 9 || ptr[i + 2] == 32) && ptr[i + 3])
			{
				str = ft_strtrim(ptr + 3, " ");
				ptr = ft_strjoin("EA ", str);
				load_identifier(ptr, 3, &(*load_2));
				return (1);
			}
		}
		i++;
	}
	return (0);
}
