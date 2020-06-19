/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2020/06/19 07:45:51 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putstr_fd_len(const char *s, int fd, ssize_t len)
{
	if (!s || len == 0)
		return ;
	write(fd, s, len);
}
/*
** #1. La chaine de caractères à écrire.
** #2. Le file descriptor sur lequel écrire.
** Valeur de retour None
** Fonctions externes autorisées
** write
** Description Écrit la chaine de caractères ’s’ sur le file
** descriptor donné.
*/
