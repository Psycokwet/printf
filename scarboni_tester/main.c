/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:24:22 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/06 10:37:12 by scarboni         ###   ########.fr       */
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

    int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 4;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
    char * str2 = "hello";
    char * str3 = "";
    char * str = "Ah que coucou bob %s%d%X%*.*s-Je suis là!%p ahaha%%sdfghjkl%05.2s5.2%i%u\n";
    //printf("printf returns %d\n", printf("%-2.4d, %-2d, %-2d, %.0d, %-15.8d, %2.2d, %2.2d\n",  j, k, l, m, c, e, d));
    //printf("ft_printf returns %d\n", ft_printf("%-2.4d, %-2d, %-2d, %.0d, %-15.8d, %2.2d, %2.2d\n",  j, k, l, m, c, e, d));
    //printf("printf returns %d\n", printf("%-4i, %-8.4d, %-2d, %-2d, %.0d, %-15.8d, %2.2d, %2.2d\n", i, j, k, l, m, c, e, d));
    //printf("ft_printf returns %d\n", ft_printf("%-4i, %-8.4d, %-2d, %-2d, %.0d, %-15.8d, %2.2d, %2.2d\n", i, j, k, l, m, c, e, d));
    printf("printf returns %d\n", printf("%4d,%-4d,%0.4d,%-0.4d,%2.4d,%-2.4d,%4.2d,%-04.8d,%04d,%-04d,%04.2d,%-04.2d,%04.8d,%-04.8d,\n", f, f, f, f, f, f, f, f, f, f, f, f, f, f));
    printf("ft_printf returns %d\n", ft_printf("%4d,%-4d,%0.4d,%-0.4d,%2.4d,%-2.4d,%4.2d,%-04.8d,%04d,%-04d,%04.2d,%-04.2d,%04.8d,%-04.8d,\n", f, f, f, f, f, f, f, f, f, f, f, f, f, f));
    printf("printf returns %d\n", printf(str, NULL, 1337, 42, 4, 2, str3, NULL, str2, 36, -2));
    printf("ft_printf returns %d\n", ft_printf(str, NULL, 1337, 42, 4, 2, str3, NULL, str2, 36, -2));
	printf("\nprintf Return : %d\n", printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf("\nft_printf Return : %d\n", ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf("\nft_printf Return : %d\n", ft_printf("%d:%d,%d:%d,,%d:%d,,%d:%d,,%d:%d,,%d:%d,,%d:%d,,%d:%d,", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	a = 0;
	printf("\nprintf Return : %d\n", printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf("\nft_printf Return : %d\n", ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf("\nft_printf Return : %d\n", ft_printf("%d:%d,%d:%d,,%d:%d,,%d:%d,,%d:%d,,%d:%d,,%d:%d,,%d:%d,", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf("\nprintf Return : %d\n", printf("[%.*i]", 0, 0));
	printf("\nft_printf Return : %d\n", ft_printf("[%.*i]", 0, 0));
	printf("\nprintf Return : %d\n", printf("[%0i]", 0));
	printf("\nft_printf Return : %d\n", ft_printf("[%0i]", 0));
	printf("\nprintf Return : %d\n", printf("[%0.0i]", 0));
	printf("\nft_printf Return : %d\n", ft_printf("[%0.0i]", 0));
	printf("\nprintf Return : %d\n", printf("[%0.*i]", 0, 42));
	printf("\nft_printf Return : %d\n", ft_printf("[%0.*i]", 0, 42));
	/*while (a < 5) //T34-69
	{   
		printf("-----------------------------------\n");

		printf("\nprintf Return : %d\n", printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\nft_printf Return : %d\n", ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\n printf Return : %d\n", printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\n ft_printf Return : %d\n", ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\n printf Return : %d\n", printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\n ft_printf Return : %d\n", ft_printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\n printf Return : %d\n", printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\n ft_printf Return : %d\n", ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		a++;
	}*/
}