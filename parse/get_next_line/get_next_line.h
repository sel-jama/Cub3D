/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboucha <yboucha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 05:13:57 by yboucha           #+#    #+#             */
/*   Updated: 2022/12/15 00:41:19 by yboucha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoi(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_strch(const char *s, int c);
char	*ft_strdup(const char *s1);
#endif
