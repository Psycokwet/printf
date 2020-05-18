/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:24:22 by scarboni          #+#    #+#             */
/*   Updated: 2020/05/11 08:53:41 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf/libft/libft.h"
#include "../ft_printf/ft_printf.h"

#include <stdarg.h>


int add(int n, ...)
{
    /* Define temporary variables */
    va_list list;
    int total;

    /* Initialize total */
    total = 0;

    /* Set where the variable length part of the argument list ends */
    va_start(list, n);

    /* Loop through each argument adding the int values */
    for (int i=0; i < n; i++){
        int tmp =  va_arg(list, int);
        printf("Excuse meeee %d%d\n",tmp);
        total = total + tmp;
    }

    /* Clean up */
    va_end(list);

    /* Return the calculated total */
    return total;
}

int main(int argc, const char * argv[])
{
    (void)argc;
    (void)argv;
    ft_printf("Ah que coucou bob %d%s ezeztze\n", 42);
}