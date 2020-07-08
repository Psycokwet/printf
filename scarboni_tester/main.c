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

int fill_buffer(char *buffer, char *str_w, int wlen, char* str_p, int plen, char* flags, int flagslen)
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
	ft_strlcpy(buffer + buffer_filling, "d|\n", 30);
	buffer_filling += 3;
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

int printf_test(char *flags, int w, int p, int d)
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
	buffer_filling = fill_buffer(BUFFER, str_w, wlen, str_p, plen, flags, flagslen);
	fill_info(INFO, BUFFER, str_w, wlen, str_p, plen, str_d, buffer_filling);

	ret = printf(BUFFER, d);
	fflush(stdout);
	ret_ft = ft_printf(BUFFER, d);
	printf("%s\n", INFO);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	buffer_filling = fill_buffer(BUFFER, "*", 1, str_p, plen, flags, flagslen);
	fill_info(INFO, BUFFER, str_w, wlen, str_p, plen, str_d, buffer_filling);

	printf(BUFFER, w, d);
	fflush(stdout);
	ft_printf(BUFFER, w, d);
	printf("%s\n", INFO);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	buffer_filling = fill_buffer(BUFFER, str_w, wlen, "*", 1, flags, flagslen);
	fill_info(INFO, BUFFER, str_w, wlen, str_p, plen, str_d, buffer_filling);
	
	printf(BUFFER, p, d);
	fflush(stdout);
	ft_printf(BUFFER, p, d);
	printf("%s\n", INFO);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	buffer_filling = fill_buffer(BUFFER, "*", 1, "*", 1, flags, flagslen);
	fill_info(INFO, BUFFER, str_w, wlen, str_p, plen, str_d, buffer_filling);
	
	printf(BUFFER, w, p, d);
	fflush(stdout);
	ft_printf(BUFFER, w, p, d);
	printf("%s\n", INFO);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	return error_count;
}



void set_flags(char * flags, int plus, int less, int zero)
{
	int i = 0;
	if(plus)
		flags[i++] = '+';
	if(less)
		flags[i++] = '-';
	if(zero)
		flags[i++] = '0';
	flags[i++] = '\0';
}

#include <stdarg.h>

int main(int argc, const char * argv[])
{
    (void)argc;
    (void)argv;
	static char * FLAGS[30];
	int w;
	int p;
	int d;

	int less;
	int zero;
	int plus;

	less = zero = plus = 0;
	
	int max = 3;
	int min = -3;
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
						while (d <= max)
						{
							set_flags(FLAGS, plus, less, zero);
							if(printf_test(FLAGS, w, p, d) != 0)
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
}