/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/08 16:06:57 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "get_next_line.h"
#include <fcntl.h>

int		main()
{
	char * lines[3];
    int i = 0;
	int ret = 1;
    int fd = 0;

	fd = open("test", O_RDONLY);
	while (ret == 1){
		ret = get_next_line(fd, &lines[i]);
        if(i == 2)
        {
            if(strcmp(lines[0], lines[1]))
                printf("Error found, datas:\n%s\n%s\n%s\n", lines[0], lines[1], lines[2]);
            free(lines[0]);
            free(lines[1]);
            free(lines[2]);
        }
        i++;
        if(i > 2)
            i = 0;
	}
    printf("If not text up here, no errors founds\n");
	return (0);
}