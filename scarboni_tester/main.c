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

int fill_buffer(char *buffer, char *str_w, int wlen, char* str_p, int plen, char* flags, int flagslen, char *convert, int convertlen)
{
	int buffer_filling = 0;
	ft_strlcpy(buffer + buffer_filling, "|%", 30);
	buffer_filling = 2;
	ft_strlcpy(buffer + buffer_filling, flags, 30);
	buffer_filling += flagslen;
	ft_strlcpy(buffer + buffer_filling, str_w, 30);
	buffer_filling += wlen;
	ft_strlcpy(buffer + buffer_filling, ".", 30);
	buffer_filling += 1;
	ft_strlcpy(buffer + buffer_filling, str_p, 30);
	buffer_filling += plen;
	ft_strlcpy(buffer + buffer_filling, convert, 30);
	buffer_filling += convertlen;
	return buffer_filling;
}

void fill_info(char *info, char *buffer, char *str_w, int wlen, char* str_p, int plen, char* str_d, int buffer_filling)
{
	ft_strlcpy(info, buffer, 30);
	buffer_filling--;
	ft_strlcpy(info + buffer_filling, str_w, 30);
	ft_strlcpy(info + buffer_filling + wlen, ":", 30);
	ft_strlcpy(info + 1 + buffer_filling + wlen, str_p, 30);
	ft_strlcpy(info + 1 + buffer_filling + wlen + plen, ":", 30);
	ft_strlcpy(info + 2 + buffer_filling + wlen + plen, str_d, 30);
}

int printf_test_numeric(char *flags, int w, int p, int d, char* convert, int convertlen)
{
	static char BUFFER[30];
	static char INFO[60];
	int buffer_filling = 0;
	int flagslen = ft_strlen(flags);
	char *str_w = ft_itoa(w);
	char *str_p = ft_itoa(p);
	char *str_d = ft_itoa(d);
	int wlen = ft_strlen(str_w);
	int plen = ft_strlen(str_p);

	int error_count = 0;
	int ret_ft = 0;
	int ret = 0;
	buffer_filling = fill_buffer(BUFFER, str_w, wlen, str_p, plen, flags, flagslen, convert, convertlen);
	fill_info(INFO, BUFFER, str_w, wlen, str_p, plen, str_d, buffer_filling);

	ret = printf(BUFFER, d);
	fflush(stdout);
	ret_ft = ft_printf(BUFFER, d);
	printf("%s\n", INFO);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	buffer_filling = fill_buffer(BUFFER, "*", 1, str_p, plen, flags, flagslen, convert, convertlen);
	fill_info(INFO, BUFFER, str_w, wlen, str_p, plen, str_d, buffer_filling);

	printf(BUFFER, w, d);
	fflush(stdout);
	ft_printf(BUFFER, w, d);
	printf("%s\n", INFO);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	buffer_filling = fill_buffer(BUFFER, str_w, wlen, "*", 1, flags, flagslen, convert, convertlen);
	fill_info(INFO, BUFFER, str_w, wlen, str_p, plen, str_d, buffer_filling);
	
	printf(BUFFER, p, d);
	fflush(stdout);
	ft_printf(BUFFER, p, d);
	printf("%s\n", INFO);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	buffer_filling = fill_buffer(BUFFER, "*", 1, "*", 1, flags, flagslen, convert, convertlen);
	fill_info(INFO, BUFFER, str_w, wlen, str_p, plen, str_d, buffer_filling);
	
	printf(BUFFER, w, p, d);
	fflush(stdout);
	ft_printf(BUFFER, w, p, d);
	printf("%s\n", INFO);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	return error_count;
}



void set_flags(char * flags, int plus, int less, int zero, int diese)
{
	int i = 0;
	if(plus)
		flags[i++] = '+';
	if(less)
		flags[i++] = '-';
	if(diese)
		flags[i++] = '#';
	if(zero)
		flags[i++] = '0';
	flags[i++] = '\0';
}

void testeur_numeric(char convert_c)
{
	static char * FLAGS[30];
	int w;
	int p;
	int d;

	int diese;
	int less;
	int zero;
	int plus;

	less = zero = plus = diese = 0;
	
	int max = 3;
	int min = -3;
	char convert[4];
	convert[0] = convert_c ;
	convert[1] = '|';
	convert[2] = '\n';
	convert[3] = '\0';

	while (diese <= 1)
	{
		diese = 0;
		while (plus <= 1)
		{
			less = 0;
			while (less <= 1)
			{
				zero = 0;
				while (zero <= 1)
				{	
					w = min;
					while (w <= max)
					{
						p = min;
						while (p <= max)
						{
							d = 0;
							while (d <= max)
							{
								set_flags(FLAGS, plus, less, zero, diese);
								if(printf_test_numeric(FLAGS, w, p, d, convert, 3) != 0)
								{
									fprintf(stderr, "Error encountered in return values, stopping now, look test for feedback\n");
								}
								d++;
							}
							p++;
						}
						w++;
					}
					zero ++;
				}
				less ++;
			}
			plus ++;
		}
		diese ++;
	}
}


int printf_test_p(char *flags, int w, int p, void *d, char* convert, int convertlen)
{
	static char BUFFER[30];
	static char INFO[60];
	int buffer_filling = 0;
	int flagslen = ft_strlen(flags);
	char *str_w = ft_itoa(w);
	char *str_p = ft_itoa(p);
	char *str_d = ft_itoa(d);
	int wlen = ft_strlen(str_w);
	int plen = ft_strlen(str_p);

	int error_count = 0;
	int ret_ft = 0;
	int ret = 0;
	buffer_filling = fill_buffer(BUFFER, str_w, wlen, str_p, plen, flags, flagslen, convert, convertlen);
	fill_info(INFO, BUFFER, str_w, wlen, str_p, plen, str_d, buffer_filling);

	ret = printf(BUFFER, d);
	fflush(stdout);
	ret_ft = ft_printf(BUFFER, d);
	printf("%s\n", INFO);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	buffer_filling = fill_buffer(BUFFER, "*", 1, str_p, plen, flags, flagslen, convert, convertlen);
	fill_info(INFO, BUFFER, str_w, wlen, str_p, plen, str_d, buffer_filling);

	printf(BUFFER, w, d);
	fflush(stdout);
	ft_printf(BUFFER, w, d);
	printf("%s\n", INFO);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	buffer_filling = fill_buffer(BUFFER, str_w, wlen, "*", 1, flags, flagslen, convert, convertlen);
	fill_info(INFO, BUFFER, str_w, wlen, str_p, plen, str_d, buffer_filling);
	
	printf(BUFFER, p, d);
	fflush(stdout);
	ft_printf(BUFFER, p, d);
	printf("%s\n", INFO);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	buffer_filling = fill_buffer(BUFFER, "*", 1, "*", 1, flags, flagslen, convert, convertlen);
	fill_info(INFO, BUFFER, str_w, wlen, str_p, plen, str_d, buffer_filling);
	
	printf(BUFFER, w, p, d);
	fflush(stdout);
	ft_printf(BUFFER, w, p, d);
	printf("%s\n", INFO);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	return error_count;
}

void testeur_p()
{
	static char * FLAGS[30];
	int w;
	int p;
	void *d;
	int i;
	int diese;
	int less;
	int zero;
	int plus;

	less = zero = plus = diese = 0;
	
	int max = 3;
	int min = -3;
	char *convert = "p|\n";

	while (diese <= 1)
	{
		diese = 0;
		while (plus <= 1)
		{
			less = 0;
			while (less <= 1)
			{
				zero = 0;
				while (zero <= 1)
				{	
					w = min;
					while (w <= max)
					{
						p = min;
						while (p <= max)
						{
							d = min;
							i = min;
							while (i < max)
							{
								set_flags(FLAGS, plus, less, zero, diese);
								if(printf_test_p(FLAGS, w, p, d, convert, 3) != 0)
								{
									fprintf(stderr, "Error encountered in return values, stopping now, look test for feedback\n");
								}
								d++;
								i++;
							}
							p++;
						}
						w++;
					}
					zero ++;
				}
				less ++;
			}
			plus ++;
		}
		diese++;
	}
}

#include <stdarg.h>

#define PRINT ft_printf
#define BPRINT(x, ...) PRINT("\"%s\" // 1st '*' = %d, 2nd '*' = %d\n", x, a, b)
int main(int argc, const char * argv[])
{
    (void)argc;
    (void)argv;
	 testeur_numeric('x');
	 testeur_numeric('X');
	// testeur_numeric('d');
	// testeur_numeric('u');
	// testeur_numeric('i');
	//testeur_p();

	// // float f = 42.123456789012345678901234567890;
	// // double d = 42.123456789012345678901234567890;
	// // double d2 = f;
	// // printf("[%f]\n", f);
	// // printf("[%f]\n", d);
	// // printf("[%f]\n", d2);
	// // ft_printf("[%f]\n", f);
	// // ft_printf("[%f]\n", d);
	// // ft_printf("[%f]\n", d2);
	// //printf("|%+0*.*d|\n",3,-1,1);
	// //ft_printf("|%+0*.*d|\n",3,-1,1);


	// 	int		a = -4;
	// int		b = 0;
	// char	c = 'a';
	// int		d = 2147483647;
	// int		e = -2147483648;
	// int		f = 42;
	// int		g = 25;
	// int		h = 4200;
	// int		i = 8;
	// int		j = -12;
	// int		k = 123456789;
	// int		l = 0;
	// int		m = -12345678;
	// char	*n = "abcdefghijklmnop";
	// char	*o = "-a";
	// char	*p = "-12";
	// char	*q = "0";
	// char	*r = "%%";
	// char	*s = "-2147483648";
	// char	*t = "0x12345678";
	// char	*u = "-0";

	// PRINT(" --- Return : %d\n", PRINT("Simple input test"));
	// PRINT(" --- Return : %d\n", PRINT("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j)); //T2
	// PRINT(" --- Return : %d\n", PRINT("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c, e, d)); //T3
	// PRINT(" --- Return : %d\n", PRINT("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d)); //T4
	// PRINT(" --- Return : %d\n", PRINT("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c, e, d)); //T5
	// PRINT(" --- Return : %d\n", PRINT("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c, e, d)); //T6
	// PRINT(" --- Return : %d\n", PRINT("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c, e, d)); //T7
	// PRINT(" --- Return : %d\n", PRINT("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c, e, d)); //T8
	// PRINT(" --- Return : %d\n", PRINT("%6i, %6d, %6d, %6d, %6d, %6d, %6d, %6d", i, j, k, l, m, c, e, d)); //T9
	// PRINT(" --- Return : %d\n", PRINT("%7i, %7d, %7d, %7d, %7d, %7d, %7d, %7d", i, j, k, l, m, c, e, d)); //T10
	// PRINT(" --- Return : %d\n", PRINT("%8i, %8d, %8d, %8d, %8d, %8d, %8d, %8d", i, j, k, l, m, c, e, d)); //T11
	// PRINT(" --- Return : %d\n", PRINT("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d)); //T12
	// PRINT(" --- Return : %d\n", PRINT("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d", i, j, k, l, m, c, e, d)); //T13
	// PRINT(" --- Return : %d\n", PRINT("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d", i, j, k, l, m, c, e, d)); //T14
	// PRINT(" --- Return : %d\n", PRINT("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d", i, j, k, l, m, c, e, d)); //T15
	// PRINT(" --- Return : %d\n", PRINT("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d", i, j, k, l, m, c, e, d)); //T16
	// PRINT(" --- Return : %d\n", PRINT("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c, e, d)); //T17
	// PRINT(" --- Return : %d\n", PRINT("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c, e, d)); //T18
	// PRINT(" --- Return : %d\n", PRINT("%-i, %-d, %-d, %-d, %-d, %-d, %-d, %-d", i, j, k, l, m, c, e, d)); //T19
	// PRINT(" --- Return : %d\n", PRINT("%.i, %.d, %.d, %.d, %.d, %.d, %.d, %.d", i, j, k, l, m, c, e, d)); //T20
	// PRINT(" --- Return : %d\n", PRINT("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d", i, j, k, l, m, c, e, d)); //T21
	// PRINT(" --- Return : %d\n", PRINT("%00i, %00d, %00d, %00d, %00d, %00d, %00d, %00d", i, j, k, l, m, c, e, d)); //T22
	// PRINT(" --- Return : %d\n", PRINT("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c, e, d)); //T23
	// PRINT(" --- Return : %d\n", PRINT("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d", i, j, k, l, m, c, e, d)); //T24
	// PRINT(" --- Return : %d\n", PRINT("%1.1i, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d", i, j, k, l, m, c, e, d)); //T25
	// PRINT(" --- Return : %d\n", PRINT("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d", i, j, k, l, m, c, e, d)); //T26
	// PRINT(" --- Return : %d\n", PRINT("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d", i, j, k, l, m, c, e, d)); //T27
	// PRINT(" --- Return : %d\n", PRINT("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1d, %-1d", i, j, k, l, m, c, e, d)); //T28
	// PRINT(" --- Return : %d\n", PRINT("%-.1i, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d", i, j, k, l, m, c, e, d)); //T29
	// PRINT(" --- Return : %d\n", PRINT("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d", i, j, k, l, m, c, e, d)); //T30
	// PRINT(" --- Return : %d\n", PRINT("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d", i, j, k, l, m, c, e, d)); //T31
	// PRINT(" --- Return : %d\n", PRINT("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d", i, j, k, l, m, c, e, d)); //T32
	// PRINT(" --- Return : %d\n", PRINT("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d", i, j, k, l, m, c, e, d)); //T33
	// while (a < 5) //T34-69
	// {
	// 	PRINT(" --- Return : %d\n", PRINT("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// 	PRINT(" --- Return : %d\n", PRINT("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// 	PRINT(" --- Return : %d\n", PRINT("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// 	PRINT(" --- Return : %d\n", PRINT("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// 	a++;
	// }
	// a = -2;
	// int it = 70;
	// while(a < 5) //T70-177
	// {
	// 	b = -2;
	// 	while (b < 5)
	// 	{
	// 		PRINT(" --- Return : %d\n", PRINT("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// 		printf("test nb %d\n", it++);
	// 		PRINT(" --- Return : %d\n", PRINT("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// 		printf("test nb %d\n", it++);
	// 		PRINT(" --- Return : %d\n", PRINT("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// 		printf("test nb %d\n", it++);
	// 		b++;
	// 	}
	// 	a++;
	// }	a = 19;
	// b = 14;
	// PRINT(" --- Return : %d\n", PRINT("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, -42, a, b, 42, -a, -b, -42, -a, -b, 42, -a, b, -42, -a, b, 42, a, -b, -42, a, -b, 42)); //T178
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%12.12i, %12.12d", -42, 42)); //T179
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%1s, %1s, %1s, %1s, %1s", n, o, p, q, r)); //T180
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%2s, %2s, %2s, %2s, %2s", n, o, p, q, r)); //T181
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%3s, %3s, %3s, %3s, %3s", n, o, p, q, r)); //T182
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%4s, %4s, %4s, %4s, %4s", n, o, p, q, r)); //T183
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%15s, %15s, %15s, %15s, %15s", n, o, p, q, r)); //T184
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%16s, %16s, %16s, %16s, %16s", n, o, p, q, r)); //T185
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%17s, %17s, %17s, %17s, %17s", n, o, p, q, r)); //T186
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%.s, %.s, %.s, %.s, %.s", n, o, p, q, r)); //T186
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%1.s, %1.s, %1.s, %1.s, %1.s", n, o, p, q, r)); //T186
	// printf("test nb %d\n", it++);

	// a = -4;
	// while (a < 5) //T187-213
	// {
	// 	PRINT(" --- Return : %d\n", PRINT("%*s, %*s, %*s, %*s, %*s, %*s, %*s, %*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
	// 	printf("test nb %d\n", it++);
	// 	PRINT(" --- Return : %d\n", PRINT("%-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
	// 	printf("test nb %d\n", it++);
	// 	PRINT(" --- Return : %d\n", PRINT("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
	// 	printf("test nb %d %d\n", it++, a);
	// a++;
	// }

	// a = -2;
	// while(a < 5) //T70-177
	// {
	// 	b = -2;
	// 	while (b < 5)
	// 	{
	// 		PRINT(" --- Return : %d\n", PRINT("%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
	// 		printf("test nb %d\n", it++);
	// 		PRINT(" --- Return : %d\n", PRINT("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
	// 		printf("test nb %d\n", it++);
	// 		b++;
	// 	}
	// 	a++;
	// }

	// PRINT(" --- Return : %d\n", PRINT("%u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X", i, i, i, j, j, j, k, k, k, l, l, l, m, m, m, c, c, c, d, d, d, e, e, e)); //T214
	// printf("test nb %d\n", it++);
	// a = -1;
	// while (a < 5) //T214-256
	// {
	// 	PRINT(" --- Return : %d\n", PRINT("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// 	printf("test nb %d\n", it++);
	// 	PRINT(" --- Return : %d\n", PRINT("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// 	printf("test nb %d\n", it++);
	// 	PRINT(" --- Return : %d\n", PRINT("%-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// 	printf("test nb %d\n", it++);
	// 	PRINT(" --- Return : %d\n", PRINT("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// 	printf("test nb %d\n", it++);
	// 	a++;
	// }
	// a = 2;
	// printf("\n\n\n");
	// printf(" --- Return : %d:%d\n", printf("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X\n", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e), ft_printf("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X\n", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));

	// a = -1;
	// while(a < 5) //T257-346
	// {
	// 	b = -1;
	// 	while (b < 5)
	// 	{
	// 		PRINT(" --- Return : %d\n", PRINT("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
			
	// printf("test nb %d\n", it++);
	// 		PRINT(" --- Return : %d\n", PRINT("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
			
	// printf("test nb %d\n", it++);
	// 		PRINT(" --- Return : %d\n", PRINT("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
			
	// printf("test nb %d\n", it++);
	// 		b++;
	// 	}
	// 	a++;
	// }
	// PRINT(" --- Return : %d\n", PRINT("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0)); //T347
	
	// printf("test nb %d\n", it++);
	// a = 8;
	// while (a < 12) //
	// {
	// 	PRINT(" --- Return : %d\n", PRINT("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
	// 	printf("test nb %d\n", it++);
	// 	PRINT(" --- Return : %d\n", PRINT("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
	// 	printf("test nb %d\n", it++);
	// 	a++;
	// }

	// printf("\n\n\n\n");
	
	// a = 8;
	// while (a < 12) //
	// {
	// 	printf(" ----- Return : %d:%d\n", ft_printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0), printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
	// 	printf("\n\n\n\n");
	// 	printf(" ----- Return : %d:%d\n", ft_printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0), printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
	// 	printf("\n\n\n\n");
	// 	a++;
	// }







	// a = f;
	// b = g;
	// PRINT(" --- Return : %d\n", PRINT("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c));
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
	// printf("test nb %d\n", it++);
	// a = 12;
	// b = 18;
	// PRINT(" --- Return : %d\n", PRINT("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c));
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], -a, p[0], -a, q[0], -a, r[0], -a, c));
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], q[0], a, q[0], a, p[0], a, p[0], a, c));
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%c,  %-c, %1c, %*c,  %-*c,  %*c", -12, -1, -255, a, -12, a, -1, a, -255));
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%%, \t, \\, \", \', +"));
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i));
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i));
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j));
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, l, a, l, a, l, a, l, a, l));
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%i, %d, %d, %d, %d, %d, %u, %x, %X", 0, 0, 0, 0, 0, 0, 0, 0, 0));
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%*i, %*d, %*d, %*d, %*d, %*d, %*u, %*x, %*X", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0));
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
	// // ^ Theoriquement un comportement indefini mais testé par la moulinette
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT("(null)"));
	// printf("test nb %d\n", it++);
	// PRINT(" --- Return : %d\n", PRINT(""));
	// printf("test nb %d\n", it++);







	// a = -4;
	// printf("\n\n\n\n");
	// printf(" ----- Return : %d:%d\n", ft_printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u), printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
	// printf("\n\n\n\n");
	// a = -3;
	// printf(" ----- Return : %d:%d\n", ft_printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u), printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
	// printf("test nb %d %d\n", it++, a);	
	// printf("\n\n\n\n");
	// a = -2;
	// printf(" ----- Return : %d:%d\n", ft_printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u), printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
	// printf("test nb %d %d\n", it++, a);
	// printf("\n\n\n\n");
	// a = -1;
	// printf(" ----- Return : %d:%d\n", ft_printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u), printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
	// printf("test nb %d %d\n", it++, a);
	// printf("\n\n\n\n");
	// a = 0;
	// printf(" ----- Return : %d:%d\n", ft_printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u), printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
	// printf("test nb %d %d\n", it++, a);
	// printf("\n\n\n\n");
	// a = 1;
	// printf(" ----- Return : %d:%d\n", ft_printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u), printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
	// printf("test nb %d %d\n", it++, a);
 	// char * str2 = "hello";
    // char * str3 = "";
	// char * str = "Ah que coucou bob %s%d%X%*.*s-Je suis là!%p ahaha%%sdfghjkl%05.2s5.2%i%u\n";
	// printf("ret %d:%d\n\n\n\n", ft_printf("ft%1s,%1s,%1s,%1s,%1s\n", n, o, p, q, r), printf("--%1s,%1s,%1s,%1s,%1s\n", n, o, p, q, r));
	// printf("ret %d:%d\n\n\n\n", ft_printf("ft%2s,%2s,%2s,%2s,%2s\n", n, o, p, q, r), printf("--%2s,%2s,%2s,%2s,%2s\n", n, o, p, q, r));
	// printf("ret %d:%d\n\n\n\n", ft_printf("ft%3s,%3s,%3s,%3s,%3s\n", n, o, p, q, r), printf("--%3s,%3s,%3s,%3s,%3s\n", n, o, p, q, r));
	// printf("ret %d:%d\n\n\n\n", ft_printf("ft,%1.0s,%1.1s,%1.2s,%1.3s,%1.4s\n", n, o, p, q, r), printf("--,%1.0s,%1.1s,%1.2s,%1.3s,%1.4s\n", n, o, p, q, r));
	// printf("ret %d:%d\n\n\n\n", ft_printf("ft,%2.0s,%2.1s,%2.2s,%2.3s,%2.4s\n", n, o, p, q, r), printf("--,%2.0s,%2.1s,%2.2s,%2.3s,%2.4s\n", n, o, p, q, r));
	// printf("ret %d:%d\n\n\n\n", ft_printf("ft,%3.0s,%3.1s,%3.2s,%3.3s,%3.4s\n", n, o, p, q, r), printf("--,%3.0s,%3.1s,%3.2s,%3.3s,%3.4s\n", n, o, p, q, r));
	// printf("printf returns %d\n", printf(str, NULL, 1337, 42, 4, 2, str3, NULL, str2, 36, -2));
    // printf("ft_printf returns %d\n", ft_printf(str, NULL, 1337, 42, 4, 2, str3, NULL, str2, 36, -2));
	// printf("printf returns %d\n", printf(str, NULL, 1337, 42, 1, 1, q, NULL, str2, 36, -2));
    // printf("ft_printf returns %d\n", ft_printf(str, NULL, 1337, 42, 1, 1, q, NULL, str2, 36, -2));
}