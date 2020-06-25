/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:24:22 by scarboni          #+#    #+#             */
/*   Updated: 2020/06/25 21:45:07 by scarboni         ###   ########.fr       */
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
    char * str = "Ah que coucou bob %X%s Je suis là!%p ahaha%%sdfghjkl%s%i%u\n";
    printf("ft_printf returns %d\n", ft_printf(str, 42, NULL, NULL, str2, 36, -2));
    printf("printf returns %d\n", printf(str, 42, NULL, NULL, str2, 36, -2));
}