/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 08:02:12 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int write_str(int fd, char *str, size_t len)
{
    int ret_read;
    //printf("WRITE\n");
    ret_read = write(fd, str, len);
    if (ret_read < 0 || (size_t)ret_read != len)
        return (-EXIT_FAILURE);
    return (ret_read);
}
