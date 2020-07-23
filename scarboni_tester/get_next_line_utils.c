/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/23 19:07:17 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			ft_gnl_strchr(const char *s, int c, ssize_t *indice, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len){
		if ((unsigned char)s[i] == c)
		{
			*indice = i;
			return (ENDL_FOUND);
		}
	}
	if ((unsigned char)s[i] == c)
	{
		*indice = i;
		return (ENDL_FOUND);
	}
	return (ENDL_NOT_FOUND);
}

size_t		ft_gnl_strdup(char **dst, const char *src, size_t len)
{
	*dst = (char *)malloc((len + 1) * sizeof(char));
	if (*dst != NULL)
		return (ft_gnl_strlcpy(*dst, src, len));
	return (0);
}

size_t		ft_gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;

	i = (size_t)-1;
	while (++i < dstsize)
		dst[i] = src[i];
	dst[i] = '\0';
	return (i);
}

int			cut_line_n(char **line, t_fd_read_wip *fd_wip)
{
	ssize_t	n_indice;
	size_t	written;
	char	*tmp;

	tmp = NULL;
	n_indice = 0;
	if (!ft_gnl_strchr(fd_wip->line_wip, '\n', &n_indice, fd_wip->size))
		return (LINE_NOT_COMPLETE);
	*line = malloc(sizeof(char) * (unsigned long)(n_indice + 1));
	if (!(*line))
		return (-EXIT_FAILURE);
	written = ft_gnl_strlcpy(*line, fd_wip->line_wip, (size_t)n_indice) + 1;
	if(fd_wip->size > written 
	&& (ft_gnl_strdup(&tmp, fd_wip->line_wip + n_indice + 1, (fd_wip->size - (n_indice + 1)))) != fd_wip->size - (written)){
		return (-EXIT_FAILURE);
	}
	free(fd_wip->line_wip);
	fd_wip->line_wip = tmp;
	fd_wip->size -= written;
	return (fd_wip->last_ret_read == 0 ? EXIT_READ_CLOSED : EXIT_READ_OPEN);
}
