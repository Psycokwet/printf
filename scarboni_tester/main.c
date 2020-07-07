/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.value.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 18:24:22 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/07 14:35:04 by scarboni         ###   ########.fr       */
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
	char	*r = "|%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
    char * str2 = "hello";
    char * str3 = "";
    char * str = "Ah que coucou bob %s%d%X%*.*s-Je suis là!%p ahaha%%sdfghjkl%05.2s5.2%i%u\n";
    //printf("printf returns %d\n", printf("|%-2.4d, %-2d, %-2d, %.0d, %-15.8d, %2.2d, %2.2d\n",  j, k, l, m, c, e, d));
    //printf("ft_printf returns %d\n", ft_printf("|%-2.4d, %-2d, %-2d, %.0d, %-15.8d, %2.2d, %2.2d\n",  j, k, l, m, c, e, d));
    //printf("printf returns %d\n", printf("|%-4i, %-8.4d, %-2d, %-2d, %.0d, %-15.8d, %2.2d, %2.2d\n", i, j, k, l, m, c, e, d));
    //printf("ft_printf returns %d\n", ft_printf("|%-4i, %-8.4d, %-2d, %-2d, %.0d, %-15.8d, %2.2d, %2.2d\n", i, j, k, l, m, c, e, d));
    printf("printf returns %d\n", printf("|%4d,%-4d,%0.4d,%-0.4d,%2.4d,%-2.4d,%4.2d,%-04.8d,%04d,%-04d,%04.2d,%-04.2d,%04.8d,%-04.8d,\n", f, f, f, f, f, f, f, f, f, f, f, f, f, f));
    printf("ft_printf returns %d\n", ft_printf("|%4d,%-4d,%0.4d,%-0.4d,%2.4d,%-2.4d,%4.2d,%-04.8d,%04d,%-04d,%04.2d,%-04.2d,%04.8d,%-04.8d,\n", f, f, f, f, f, f, f, f, f, f, f, f, f, f));
    printf("printf returns %d\n", printf(str, NULL, 1337, 42, 4, 2, str3, NULL, str2, 36, -2));
    printf("ft_printf returns %d\n", ft_printf(str, NULL, 1337, 42, 4, 2, str3, NULL, str2, 36, -2));
	printf("\nprintf Return : %d\n", printf("|%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d|", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf("\nft_printf Return : %d\n", ft_printf("|%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d|", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf("\nft_printf Return : %d\n", ft_printf("|%d:%d,%d:%d,,%d:%d,,%d:%d,,%d:%d,,%d:%d,,%d:%d,,%d:%d,", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	a = 0;
	printf("\nprintf Return : %d\n", printf("|%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d|", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf("\nft_printf Return : %d\n", ft_printf("|%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d|", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf("\nft_printf Return : %d\n", ft_printf("|%d:%d,%d:%d,,%d:%d,,%d:%d,,%d:%d,,%d:%d,,%d:%d,,%d:%d,", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf("\nprintf Return : %d\n", printf("[%.*i]", 0, 0));
	printf("\nft_printf Return : %d\n", ft_printf("[%.*i]", 0, 0));
	printf("\nprintf Return : %d\n", printf("[%0i]", 0));
	printf("\nft_printf Return : %d\n", ft_printf("[%0i]", 0));
	printf("\nprintf Return : %d\n", printf("[%0.0i]", 0));
	printf("\nft_printf Return : %d\n", ft_printf("[%0.0i]", 0));
	printf("\nprintf Return : %d\n", printf("[%0.*i]", 0, 42));
	printf("\nft_printf Return : %d\n", ft_printf("[%0.*i]", 0, 42));
	 a = -1;
	printf("\n printf Return : %d\n", printf("|%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d|", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf("\n ft_printf Return : %d\n", ft_printf("|%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d|", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	 a = 3;
	printf("\n printf Return : %d\n", printf("|%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d|", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf("\n ft_printf Return : %d\n", ft_printf("|%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d|", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf("\nft_printf Return : %d\n", ft_printf("|%d:%d,%d:%d,,%d:%d,,%d:%d,,%d:%d,,%d:%d,,%d:%d,,%d:%d,", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));


	 a = 3;
		printf("------------%%.*d-----------------\n");
	printf("\n printf Return : %d\n", printf(",%.*d,", a, j));
	printf("\n ft_printf Return : %d\n", ft_printf(",%.*d,", a, j));
		printf("------------%%.*d-----------------\n");
	printf("\n printf Return : %d\n", printf(",%.*d,", a, -2));
	printf("\n ft_printf Return : %d\n", ft_printf(",%.*d,", a, -2));
		printf("------------%%0*d-----------------\n");
	printf("\n printf Return : %d\n", printf(",%0*d,",  a, j));
	printf("\n ft_printf Return : %d\n", ft_printf(",%0*d,",  a, j));
		printf("------------%%0*d-----------------\n");
	printf("\n printf Return : %d\n", printf(",%0*d,",  a, -2));
	printf("\n ft_printf Return : %d\n", ft_printf(",%0*d,",  a, -2));
		printf("-----------------------------------\n");
	printf("\nft_printf Return : %d\n", ft_printf("|%d:%d|", a, j));
	
	a = -2;
	b = -2;
		printf("----------------%%*.*i,%%*.*d---------8, -4, i, -8, -4, l------\n");
	printf(" aprintf Return : %d\n", printf("a%*.*i,%*.*d,", -8, -4, i, -8, -4, l));
	ft_printf(" anft_printf Return : %d\n", ft_printf("a%*.*i,%*.*d,", -8, -4, i, -8, -4, l));
		printf("----------------different linux/mac-----b%%-2.-2i,%%-2.-2d--------------\n");
	printf(" bprintf Return : %d\n", printf("b%-2.-2i,%-2.-2d,%d,%d,", i, l));
	ft_printf(" bnft_printf Return : %d\n", ft_printf("b%-2.-2i,%-2.-2d,", i, l));
		printf("------------------b%%2.-2i,%%2.-2d-----------------\n");
	printf(" bprintf Return : %d\n", printf("b%2.-2i,%2.-2d,", i, l));
	ft_printf(" bnft_printf Return : %d\n", ft_printf("b%2.-2i,%2.-2d,", i, l));
		printf("----------------------\\-------------\n");
	printf(" bprintf Return : %d\n", printf("b%+-2.2i,%-2.2d,", i, l));
	ft_printf(" bnft_printf Return : %d\n", ft_printf("b%+-2.2i,%-2.2d,", i, l));
		printf("-----------------------------------\n");
	printf("\nft_printf Return : %d\n", ft_printf("|%d:%d:%d,%d:%d:%d,",  a, b, i, a, b, l));

	a = 4;
	b = -1;

	ft_printf(" ft_printf Return : %d\n", ft_printf("|%*.*i, %*.*d, %*.*d, %*.*d,", a, b, i, a, b, j, a, b, l, a, b, c));
	printf(" printf Return : %d\n", printf("|%*.*i, %*.*d, %*.*d, %*.*d,", a, b, i, a, b, j, a, b, l, a, b, c));
	
	printf("\nft_printf Return : %d\n", ft_printf("|%d:%d:%d,,,,%d:%d:%d,,,,%d:%d:%d,,,,%d:%d:%d,",a, b, i, a, b, j, a, b, l, a, b, c));


	a = 3;
	b = -5;
	printf("----------%%0*.*i, %%0*.*d------a:%d b:%d----------------\n", a, b);
	ft_printf(" ft_printf Return : %d\n", ft_printf("|%0*.*i, %0*.*d,", a, b, i, a, b, l));
	printf(" printf Return : %d\n", printf("|%0*.*i, %0*.*d,", a, b, i, a, b, l));
	printf("\nft_printf Return : %d\n", ft_printf("|%d:%d:%d,,,,%d:%d:%d,", a, b, i, a, b, l));

	a = -2;
	b = -2;
	printf("----------------%%0*.*i, %%0*.*d--a:%d b:%d----------------\n", a, b);
	ft_printf(" ft_printf Return : %d\n", ft_printf("|%0*.*i, %0*.*d,", a, b, i, a, b, l));
	printf(" printf Return : %d\n", printf("|%0*.*i, %0*.*d,", a, b, i, a, b, l));
	printf("\nft_printf Return : %d\n", ft_printf("|%d:%d:%d,,,,%d:%d:%d,", a, b, i, a, b, l));
	int value = 0;
	printf("\n-----------\n");
	printf("|%.d|", value);
	printf("\n");
	ft_printf("|%.d|", value);
	printf("\n-----------\n");
	printf("|%.0|", value);
	printf("\n");
	ft_printf("|%.0|", value);
	printf("\n-----------\n");
	printf("|%.0000042|", value);
	printf("\n");
	ft_printf("|%.0000042|", value);
	printf("\n-----------\n");
	printf("|%.*|", -value, value);
	printf("\n");
	ft_printf("|%.*|", -value, value);
	printf("\n-----------\n");
	printf("|%.*|", 0, value);
	printf("\n");
	ft_printf("|%.*|", 0, value);
	printf("\n-----------\n");
	printf("|%.*|", 0, 0);
	printf("\n");
	ft_printf("|%.*|", 0, 0);
	printf("\n-----------\n");
	printf("|%...*|", value, value);
	printf("\n");
	ft_printf("|%...*|", value, value);


	printf("\n------%%d-----\n");
	printf("|%d|", value);
	printf("\n");
	ft_printf("|%d|", value);

	printf("\n------on the *-----\n");
	printf("\n------%%*d-----\n", 4);
	printf("|%*d|", 4, value);
	printf("\n");
	ft_printf("|%*d|", 4, value);

	printf("\n-----%%0*d------\n");
	printf("|%0*d|", 4, value);
	printf("\n");
	ft_printf("|%0*d|", 4, value);

	printf("\n-----%%-0*d------\n");
	printf("|%-0*d|", 4, value);
	printf("\n");
	ft_printf("|%-0*d|", 4, value);

	printf("\n------%%-*d-----\n");
	printf("|%-*d|", 4, value);
	printf("\n");
	ft_printf("|%-*d|", 4, value);



	printf("\n------on the format_s-----\n");

	printf("\n------%%4d-----\n");
	printf("|%4d|", value);
	printf("\n");
	ft_printf("|%4d|", value);

	printf("\n-----%%04d------\n");
	printf("|%04d|", value);
	printf("\n");
	ft_printf("|%04d|", value);

	printf("\n-----%%-04d------\n");
	printf("|%-04d|", value);
	printf("\n");
	ft_printf("|%-04d|", value);

	printf("\n------%%-4d-----\n");
	printf("|%-4d|", value);
	printf("\n");
	ft_printf("|%-4d|", value);


	printf("\n------on the *-----\n");
	printf("\n------%%*d-----\n", 4);
	printf("|%*d|", 4, value);
	printf("\n");
	ft_printf("|%*d|", 4, value);

	printf("\n-----%%0*d------\n");
	printf("|%0*d|", 4, value);
	printf("\n");
	ft_printf("|%0*d|", 4, value);

	printf("\n-----%%-0*d------\n");
	printf("|%-0*d|", 4, value);
	printf("\n");
	ft_printf("|%-0*d|", 4, value);

	printf("\n------%%-*d-----\n");
	printf("|%-*d|", 4, value);
	printf("\n");
	ft_printf("|%-*d|", 4, value);



	printf("\n------WITH PRECISION-----\n");
	printf("\n------on the *****-----\n");


	printf("\n------%%4d.-----\n");
	printf("|%4.d|", value);
	printf("\n");
	ft_printf("|%4.d|", value);

	printf("\n------%%4d.*  (3-----\n");
	printf("|%4.*d|", 3, value);
	printf("\n");
	ft_printf("|%4.*d|", 3, value);

	printf("\n------%%4d.*  (6-----\n");
	printf("|%4.*d|", 6, value);
	printf("\n");
	ft_printf("|%4.*d|", 6, value);

	printf("\n------%%4d.*  (-6-----\n");
	printf("|%4.*d|", -6, value);
	printf("\n");
	ft_printf("|%4.*d|", -6, value);



	printf("\n------%%04d.-----\n");
	printf("|%04.d|", value);
	printf("\n");
	ft_printf("|%04.d|", value);

	printf("\n------%%04d.*  (3-----\n");
	printf("|%04.*d|", 3, value);
	printf("\n");
	ft_printf("|%04.*d|", 3, value);

	printf("\n------%%04d.*  (6-----\n");
	printf("|%04.*d|", 6, value);
	printf("\n");
	ft_printf("|%04.*d|", 6, value);

	printf("\n------%%04d.*  (-6-----\n");
	printf("|%04.*d|", -6, value);
	printf("\n");
	ft_printf("|%04.*d|", -6, value);



	printf("\n------%%-04d.-----\n");
	printf("|%-04.d|", value);
	printf("\n");
	ft_printf("|%-04.d|", value);

	printf("\n------%%-04d.*  (3-----\n");
	printf("|%-04.*d|", 3, value);
	printf("\n");
	ft_printf("|%-04.*d|", 3, value);

	printf("\n------%%-04d.*  (6-----\n");
	printf("|%-04.*d|", 6, value);
	printf("\n");
	ft_printf("|%-04.*d|", 6, value);

	printf("\n------%%-04d.*  (-6-----\n");
	printf("|%-04.*d|", -6, value);
	printf("\n");
	ft_printf("|%-04.*d|", -6, value);

	printf("\n------%%-4d.-----\n");
	printf("|%-4.d|", value);
	printf("\n");
	ft_printf("|%-4.d|", value);

	printf("\n------%%-4d.*  (3)-----\n");
	printf("|%-4.*d|", 3, value);
	printf("\n");
	ft_printf("|%-4.*d|", 3, value);

	printf("\n------%%-4d.*  (6)-----\n");
	printf("|%-4.*d|", 6, value);
	printf("\n");
	ft_printf("|%-4.*d|", 6, value);

	printf("\n------%%-4d.*  (-6)-----\n");
	printf("|%-4.*d|", -6, value);
	printf("\n");
	ft_printf("|%-4.*d|", -6, value);



	printf("\n------on the format_s-----\n");

	printf("\n------%%4d.-----\n");
	printf("|%4.d|", value);
	printf("\n");
	ft_printf("|%4.d|", value);

	printf("\n------%%4d.3-----\n");
	printf("|%4.3d|", value);
	printf("\n");
	ft_printf("|%4.3d|", value);

	printf("\n------%%4d.6-----\n");
	printf("|%4.6d|", value);
	printf("\n");
	ft_printf("|%4.6d|", value);

	printf("\n------%%4d.-6-----\n");
	printf("|%4.-6d|", value);
	printf("\n");
	ft_printf("|%4.-6d|", value);



	printf("\n------%%04d.-----\n");
	printf("|%04.d|", value);
	printf("\n");
	ft_printf("|%04.d|", value);

	printf("\n------%%04d.3-----\n");
	printf("|%04.3d|", value);
	printf("\n");
	ft_printf("|%04.3d|", value);

	printf("\n------%%04d.6-----\n");
	printf("|%04.6d|", value);
	printf("\n");
	ft_printf("|%04.6d|", value);

	printf("\n------%%04d.-6-----\n");
	printf("|%04.-6d|", value);
	printf("\n");
	ft_printf("|%04.-6d|", value);



	printf("\n------%%-04d.-----\n");
	printf("|%-04.d|", value);
	printf("\n");
	ft_printf("|%-04.d|", value);

	printf("\n------%%-04d.3-----\n");
	printf("|%-04.3d|", value);
	printf("\n");
	ft_printf("|%-04.3d|", value);

	printf("\n------%%-04d.6-----\n");
	printf("|%-04.6d|", value);
	printf("\n");
	ft_printf("|%-04.6d|", value);

	printf("\n------%%-04d.-6-----\n");
	printf("|%-04.-6d|", value);
	printf("\n");
	ft_printf("|%-04.-6d|", value);

	printf("\n------%%-4d.-----\n");
	printf("|%-4.d|", value);
	printf("\n");
	ft_printf("|%-4.d|", value);

	printf("\n------%%-4d.3-----\n");
	printf("|%-4.3d|", value);
	printf("\n");
	ft_printf("|%-4.3d|", value);

	printf("\n------%%-4d.6-----\n");
	printf("|%-4.6d|", value);
	printf("\n");
	ft_printf("|%-4.6d|", value);

	printf("\n------%%-4d.-6-----\n");
	printf("|%-4.-6d|", value);
	printf("\n");
	ft_printf("|%-4.-6d|", value);


	printf("\n------end-----\n");

	value = 42;
	printf("\n-----------\n");
	printf("|%.d|", value);
	printf("\n");
	ft_printf("|%.d|", value);
	printf("\n-----------\n");
	printf("|%.0|", value);
	printf("\n");
	ft_printf("|%.0|", value);
	printf("\n-----------\n");
	printf("|%.0000042|", value);
	printf("\n");
	ft_printf("|%.0000042|", value);
	printf("\n-----------\n");
	printf("|%.*|", -value, value);
	printf("\n");
	ft_printf("|%.*|", -value, value);
	printf("\n-----------\n");
	printf("|%.*|", 0, value);
	printf("\n");
	ft_printf("|%.*|", 0, value);
	printf("\n-----------\n");
	printf("|%.*|", 0, 0);
	printf("\n");
	ft_printf("|%.*|", 0, 0);
	printf("\n-----------\n");
	printf("|%...*|", value, value);
	printf("\n");
	ft_printf("|%...*|", value, value);

	printf("\n------%%d-----\n");
	printf("|%d|", value);
	printf("\n");
	ft_printf("|%d|", value);

	printf("\n------on the *-----\n");
	printf("\n------%%*d-----\n", 4);
	printf("|%*d|", 4, value);
	printf("\n");
	ft_printf("|%*d|", 4, value);

	printf("\n-----%%0*d------\n");
	printf("|%0*d|", 4, value);
	printf("\n");
	ft_printf("|%0*d|", 4, value);

	printf("\n-----%%-0*d------\n");
	printf("|%-0*d|", 4, value);
	printf("\n");
	ft_printf("|%-0*d|", 4, value);

	printf("\n------%%-*d-----\n");
	printf("|%-*d|", 4, value);
	printf("\n");
	ft_printf("|%-*d|", 4, value);



	printf("\n------on the format_s-----\n");

	printf("\n------%%4d-----\n");
	printf("|%4d|", value);
	printf("\n");
	ft_printf("|%4d|", value);

	printf("\n-----%%04d------\n");
	printf("|%04d|", value);
	printf("\n");
	ft_printf("|%04d|", value);

	printf("\n-----%%-04d------\n");
	printf("|%-04d|", value);
	printf("\n");
	ft_printf("|%-04d|", value);

	printf("\n------%%-4d-----\n");
	printf("|%-4d|", value);
	printf("\n");
	ft_printf("|%-4d|", value);


	printf("\n------on the *-----\n");
	printf("\n------%%*d-----\n", 4);
	printf("|%*d|", 4, value);
	printf("\n");
	ft_printf("|%*d|", 4, value);

	printf("\n-----%%0*d------\n");
	printf("|%0*d|", 4, value);
	printf("\n");
	ft_printf("|%0*d|", 4, value);

	printf("\n-----%%-0*d------\n");
	printf("|%-0*d|", 4, value);
	printf("\n");
	ft_printf("|%-0*d|", 4, value);

	printf("\n------%%-*d-----\n");
	printf("|%-*d|", 4, value);
	printf("\n");
	ft_printf("|%-*d|", 4, value);



	printf("\n------WITH PRECISION-----\n");
	printf("\n------on the *****-----\n");


	printf("\n------%%4d.-----\n");
	printf("|%4.d|", value);
	printf("\n");
	ft_printf("|%4.d|", value);

	printf("\n------%%4d.*  (3-----\n");
	printf("|%4.*d|", 3, value);
	printf("\n");
	ft_printf("|%4.*d|", 3, value);

	printf("\n------%%4d.*  (6-----\n");
	printf("|%4.*d|", 6, value);
	printf("\n");
	ft_printf("|%4.*d|", 6, value);

	printf("\n------%%4d.*  (-6-----\n");
	printf("|%4.*d|", -6, value);
	printf("\n");
	ft_printf("|%4.*d|", -6, value);



	printf("\n------%%04d.-----\n");
	printf("|%04.d|", value);
	printf("\n");
	ft_printf("|%04.d|", value);

	printf("\n------%%04d.*  (3-----\n");
	printf("|%04.*d|", 3, value);
	printf("\n");
	ft_printf("|%04.*d|", 3, value);

	printf("\n------%%04d.*  (6-----\n");
	printf("|%04.*d|", 6, value);
	printf("\n");
	ft_printf("|%04.*d|", 6, value);

	printf("\n------%%04d.*  (-6-----\n");
	printf("|%04.*d|", -6, value);
	printf("\n");
	ft_printf("|%04.*d|", -6, value);



	printf("\n------%%-04d.-----\n");
	printf("|%-04.d|", value);
	printf("\n");
	ft_printf("|%-04.d|", value);

	printf("\n------%%-04d.*  (3-----\n");
	printf("|%-04.*d|", 3, value);
	printf("\n");
	ft_printf("|%-04.*d|", 3, value);

	printf("\n------%%-04d.*  (6-----\n");
	printf("|%-04.*d|", 6, value);
	printf("\n");
	ft_printf("|%-04.*d|", 6, value);

	printf("\n------%%-04d.*  (-6-----\n");
	printf("|%-04.*d|", -6, value);
	printf("\n");
	ft_printf("|%-04.*d|", -6, value);

	printf("\n------%%-4d.-----\n");
	printf("|%-4.d|", value);
	printf("\n");
	ft_printf("|%-4.d|", value);

	printf("\n------%%-4d.*  (3)-----\n");
	printf("|%-4.*d|", 3, value);
	printf("\n");
	ft_printf("|%-4.*d|", 3, value);

	printf("\n------%%-4d.*  (6)-----\n");
	printf("|%-4.*d|", 6, value);
	printf("\n");
	ft_printf("|%-4.*d|", 6, value);

	printf("\n------%%-4d.*  (-6)-----\n");
	printf("|%-4.*d|", -6, value);
	printf("\n");
	ft_printf("|%-4.*d|", -6, value);



	printf("\n------on the format_s-----\n");

	printf("\n------%%4d.-----\n");
	printf("|%4.d|", value);
	printf("\n");
	ft_printf("|%4.d|", value);

	printf("\n------%%4d.3-----\n");
	printf("|%4.3d|", value);
	printf("\n");
	ft_printf("|%4.3d|", value);

	printf("\n------%%4d.6-----\n");
	printf("|%4.6d|", value);
	printf("\n");
	ft_printf("|%4.6d|", value);

	printf("\n------%%4d.-6-----\n");
	printf("|%4.-6d|", value);
	printf("\n");
	ft_printf("|%4.-6d|", value);



	printf("\n------%%04d.-----\n");
	printf("|%04.d|", value);
	printf("\n");
	ft_printf("|%04.d|", value);

	printf("\n------%%04d.3-----\n");
	printf("|%04.3d|", value);
	printf("\n");
	ft_printf("|%04.3d|", value);

	printf("\n------%%04d.6-----\n");
	printf("|%04.6d|", value);
	printf("\n");
	ft_printf("|%04.6d|", value);

	printf("\n------%%04d.-6-----\n");
	printf("|%04.-6d|", value);
	printf("\n");
	ft_printf("|%04.-6d|", value);



	printf("\n------%%-04d.-----\n");
	printf("|%-04.d|", value);
	printf("\n");
	ft_printf("|%-04.d|", value);

	printf("\n------%%-04d.3-----\n");
	printf("|%-04.3d|", value);
	printf("\n");
	ft_printf("|%-04.3d|", value);

	printf("\n------%%-04d.6-----\n");
	printf("|%-04.6d|", value);
	printf("\n");
	ft_printf("|%-04.6d|", value);

	printf("\n------%%-04d.-6-----\n");
	printf("|%-04.-6d|", value);
	printf("\n");
	ft_printf("|%-04.-6d|", value);

	printf("\n------%%-4d.-----\n");
	printf("|%-4.d|", value);
	printf("\n");
	ft_printf("|%-4.d|", value);

	printf("\n------%%-4d.3-----\n");
	printf("|%-4.3d|", value);
	printf("\n");
	ft_printf("|%-4.3d|", value);

	printf("\n------%%-4d.6-----\n");
	printf("|%-4.6d|", value);
	printf("\n");
	ft_printf("|%-4.6d|", value);

	printf("\n------%%-4d.-6-----\n");
	printf("|%-4.-6d|", value);
	printf("\n");
	ft_printf("|%-4.-6d|", value);


	printf("\n------end-----\n");
	// a = -2;
	// int at = 70;
	// while(a < 5) //T70-177
	// {
	// 	b = -2;
	// 	while (b < 5)
	// 	{
	// 		printf("----------------%d--a:%d b:%d----------------\n", at ++, a, b);
	// 		ft_printf(" ft_printf Return : %d\n", ft_printf("|%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d|", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// 		printf(" printf Return : %d\n", printf("|%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d|", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
			
	// 		printf("----------------%d--a:%d b:%d----------------\n", at ++, a, b);
	// 		ft_printf(" ft_printf Return : %d\n", ft_printf("|%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d|", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// 		printf(" printf Return : %d\n", printf("|%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d|", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
			
	// 		printf("----------------%d--a:%d b:%d----------------\n", at ++, a, b);
	// 		ft_printf(" ft_printf Return : %d\n", ft_printf("|%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d|", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// 		printf(" printf Return : %d\n", printf("|%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d|", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// 		b++;
	// 	}
	// 	a++;
	// }
	
	/*while (a < 5) //T34-69
	{   
		printf("-----------------------------------\n");

		printf("\nprintf Return : %d\n", printf("|%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d|", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\nft_printf Return : %d\n", ft_printf("|%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d|", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\n printf Return : %d\n", printf("|%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d|", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\n ft_printf Return : %d\n", ft_printf("|%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d|", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\n printf Return : %d\n", printf("|%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d|", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\n ft_printf Return : %d\n", ft_printf("|%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d|", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\n printf Return : %d\n", printf("|%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d|", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		printf("\n ft_printf Return : %d\n", ft_printf("|%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d|", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		a++;
	}*/
}