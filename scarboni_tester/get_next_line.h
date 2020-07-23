/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:14:23 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/23 07:35:47 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_fd_read_wip
{
	int			fd;
	ssize_t		last_ret_read;
	size_t		size;
	char		*line_wip;
}				t_fd_read_wip;

# define EXIT_READ_OPEN		1
# define EXIT_READ_CLOSED	0

# define APPEND_SUCCES		0

# define LINE_NOT_COMPLETE	2

# define INIT_RET_READ		-2

# define ENDL_FOUND			1
# define ENDL_NOT_FOUND		0

int				ft_gnl_strchr(const char *s, int c, ssize_t *indice, size_t len);
size_t			ft_gnl_strdup(char **dst, const char *src, size_t len);
size_t			ft_gnl_strlcpy(char *dst, const char *src, size_t dstsize);
int				cut_line_n(char **line, t_fd_read_wip *fd_wip);
int				append_buffer(t_fd_read_wip *fd_wip, char *buffer,
size_t ret_read);
int				read_full_line(t_fd_read_wip *fd_wip, char **line,
				char *buffer);
void			set_current_wip(t_fd_read_wip *current_wip, int fd);
int				get_next_line(int fd, char **line);

#endif
