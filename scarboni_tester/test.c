/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/23 19:15:35 by scarboni         ###   ########.fr       */
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
    int error_count = 0;
	int ret = 1;
    int fd = 0;

    for(i = 0; i < 3; i++)
        lines[i] = NULL;
    i = 0;
    fd = open("test", O_RDONLY);
	while (ret == 1){
		ret = get_next_line(fd, &lines[i]);
        if(i == 2)
        {
            if(strcmp(lines[0], lines[1]))
                printf("Error %d found, datas:\n%s\n%s\n%s\n", ++error_count, lines[0], lines[1], lines[2]);
            free(lines[0]);
            lines[0] = NULL;
            free(lines[1]);
            lines[1] = NULL;
            free(lines[2]);
            lines[2] = NULL;
        }
        i++;
        if(i > 2)
            i = 0;
	}
    for(i = 0; i < 3; i++)
        if(lines[i])
            free(lines[i]);
    printf("%d errors founds\n", error_count);
	return (0);
}