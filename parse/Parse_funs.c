/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_funs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:46:35 by yboucha           #+#    #+#             */
/*   Updated: 2024/01/05 16:34:59 by yboucha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube.h"

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
	if (!ptr)
		exit(0);
	while (ptr[i])
	{
		if ((ptr[i] >= '0' && ptr[i] <= '9') || (ptr[i] == 'N'
				&& ptr[i + 1] != 'O') || (ptr[i] == 'S' && ptr[i + 1] != 'O')
			|| (ptr[i] == 'W' && ptr[i + 1] != 'E')
			|| (ptr[i] == 'E' && ptr[i + 1] != 'A'))
			return (1);
		i++;
	}
	return (0);
}

int	norming(char **p, t_path **load, char **s, int i)
{
	char	*ptr;
	char	*str;
	char	*tmp;

	tmp = NULL;
	ptr = *p;
	str = *s;
	tmp = (ptr + (i + 3));
	str = ft_strtrim(tmp, " ");
	free (ptr);
	ptr = ft_strjoin((*load)->box, str);
	free (str);
	load_identifier(ptr, 3, load);
	return (1);
}

char	*norming2(char **p, char **s, char *f_or_c)
{
	char	*ptr;
	char	*str;

	ptr = *p;
	str = *s;
	free(ptr);
	ptr = ft_strjoin(f_or_c, str);
	return (ptr);
}

int	do_this(char **p, t_path **load, char **s, int i)
{
	char	*ptr;
	char	*str;

	ptr = *p;
	str = *s;
	if ((ptr[i + 2] == 9 || ptr[i + 2] == 32) && ptr[i + 3])
	{
		(*load)->box = "NO ";
		norming(&ptr, load, &str, i);
	}
	else
		ft_errors();
	return (1);
}

int	parametere_map2(char *ptr, t_path **load, char *str, int i)
{
	char	*tmp;

	tmp = NULL;
	if ((ptr[i] == 'F' || ptr[i] == 'C'))
	{
		if ((ptr[i + 1] == 9 || ptr[i + 1] == 32) && ptr[i + 2])
		{
			tmp = (ptr + (i + 2));
			str = ft_strtrim(tmp, "  ");
			if (ptr[i] == 'F')
				ptr = norming2(&ptr, &str, "F ");
			else
				ptr = norming2(&ptr, &str, "C ");
			free(str);
			load_identifier(ptr, 2, &(*load));
			return (1);
		}
		else
			ft_errors();
	}
	if (ptr[i] == 'N' && ptr[i + 1] && ptr[i + 1] == 'O')
		return (do_this(&ptr, load, &str, i));
	return (0);
}

int	parametere_map3(char *ptr, t_path **load, char *str, int i)
{
	if (ptr[i] == 'S' && ptr[i + 1] && ptr[i + 1] == 'O')
	{
		if ((ptr[i + 2] == 9 || ptr[i + 2] == 32) && ptr[i + 3])
		{
			(*load)->box = "SO ";
			return (norming(&ptr, load, &str, i));
		}
		else
			ft_errors();
	}
	else if (ptr[i] == 'W' && ptr[i + 1] && ptr[i + 1] == 'E')
	{
		if ((ptr[i + 2] == 9 || ptr[i + 2] == 32) && ptr[i + 3])
		{
			(*load)->box = "WE ";
			return (norming(&ptr, load, &str, i));
		}
		else
			ft_errors();
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
				(*load_2)->box = "EA ";
				return (norming(&ptr, load_2, &str, i));
			}
			else
				ft_errors();
		}
		i++;
	}
	return (0);
}
