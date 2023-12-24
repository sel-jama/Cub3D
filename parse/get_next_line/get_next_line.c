/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboucha <yboucha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 05:11:00 by yboucha           #+#    #+#             */
/*   Updated: 2023/12/24 06:30:19 by sel-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*last(char **lst)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	while (*(*lst + i) && *(*lst + i) != '\n')
		i++;
	if (*(*lst + i) == '\n')
		i++;
	j = 0;
	s = malloc(ft_strlen(*lst) - i + 1);
	if (!s)
	{
		free(*lst);
		return (NULL);
	}
	while (*(*lst + i))
		s[j++] = *(*lst + i++);
	if (*(*lst + i) == '\n')
		s[j++] = '\n';
	s[j] = '\0';
	free(*lst);
	return (s);
}

char	*ret_line(char *line)
{
	char	*l;
	int		i;

	i = 1;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	l = malloc (i + 1);
	if (!l)
		return (NULL);
	i = -1;
	while (line[++i] && line[i] != '\n')
		l[i] = line[i];
	if (line[i] == '\n')
		l[i++] = '\n';
	l[i] = '\0';
	return (l);
}

char	*ft_read(int fd, char **b)
{
	char	*s;
	int		i;

	if (!(*b))
		*b = ft_strdup("");
	i = 1;
	if (ft_strch(*b, '\n'))
		return (*b);
	s = malloc(BUFFER_SIZE + 1);
	while (!ft_strch(*b, '\n') && i != 0)
	{
		i = read(fd, s, BUFFER_SIZE);
		if (i == -1 || (i == 0 && *(*b) == '\0'))
		{
			free(s);
			free(*b);
			return (NULL);
		}
		s[i] = '\0';
		*b = ft_strjoi(*b, s);
	}
	free(s);
	return (*b);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, &buffer);
	if (!buffer)
		return (NULL);
	l = ret_line(buffer);
	buffer = last(&buffer);
	return (l);
}
