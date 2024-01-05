/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_funs_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jama <sel-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:57:57 by sel-jama          #+#    #+#             */
/*   Updated: 2024/01/05 18:59:41 by sel-jama         ###   ########.fr       */
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
