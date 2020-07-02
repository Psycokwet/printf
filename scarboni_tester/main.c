/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:24:22 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/02 16:56:17 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf/libft/libft.h"
#include "../ft_printf/ft_printf.h"

#include <stdarg.h>

int main(int argc, const char * argv[])
{
    (void)argc;
    (void)argv;
    char * str2 = "hello";
    char * str3 = "";
    char * str = "Ah que coucou bob %d%X%*.*s-Je suis là!%p ahaha%%sdfghjkl%-05.2s5.2%i%u\n";
    printf("printf returns %d\n", printf(str, 1337, 42, 4, 2, str3, NULL, str2, 36, -2));
    printf("ft_printf returns %d\n", ft_printf(str, 1337, 42, 4, 2, str3, NULL, str2, 36, -2));
}   
