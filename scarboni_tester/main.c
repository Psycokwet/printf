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


static const char * POSSIBLE_FLAGS = "+-#0";
static const int NBR_FLAGS = 4;
static const int max = 6;
static const int min = -max;
static const char max_c = 126;
static const char min_c = -max -1;


typedef struct		s_test_data
{
	unsigned long int		active_flags;

	int 	w;
	int 	p;
	int 	d;

	void* 	p_value;

	char	*str_w;
	int		wlen;
	char	*str_p;
	int		plen;
	char	*str_value;
	int		valuelen;

	char	flags[30];
	int		flagslen;
	char	info[60];
	int		infolen;
	char	convert[30];
	int		convertlen;
	char	buffer[30];
	int		bufferlen;
}					t_test_data;

#include<string.h>

void fill_buffer(t_test_data * datas, char *str_w, int wlen, char *str_p, int plen, int point)
{
	int buffer_filling = 0;
	ft_strlcpy(datas->buffer + buffer_filling, "|%", 30);
	buffer_filling = 2;
	ft_strlcpy(datas->buffer + buffer_filling, datas->flags, 30);
	buffer_filling += datas->flagslen;
	ft_strlcpy(datas->buffer + buffer_filling, str_w, 30);
	buffer_filling += wlen;
	if(point == 1){
		ft_strlcpy(datas->buffer + buffer_filling, ".", 30);
		buffer_filling += 1;
	}
	ft_strlcpy(datas->buffer + buffer_filling, str_p, 30);
	buffer_filling += plen;
	ft_strlcpy(datas->buffer + buffer_filling, datas->convert, 30);
	buffer_filling += datas->convertlen;
	datas->bufferlen = buffer_filling;
}


void fill_info(t_test_data * datas)
{
	int i = 0;
	ft_strlcpy(datas->info, datas->buffer, 30);
	i += datas->bufferlen -2;
	ft_strlcpy(datas->info + i, datas->str_w, 30);
	i += datas->wlen;
	ft_strlcpy(datas->info + i, ":", 30);
	i += 1;
	ft_strlcpy(datas->info + i, datas->str_p, 30);
	i += datas->plen;
	ft_strlcpy(datas->info + i, ":", 30);
	i += 1;
	ft_strlcpy(datas->info + i, datas->str_value, 30);
	i += datas->valuelen;
	datas->infolen = i;
}

void set_flags(t_test_data * datas)
{
	int i = 0;
	int index = 0;
	while(i < NBR_FLAGS){
		if (datas->active_flags >> i & 1)
			datas->flags[index++] = POSSIBLE_FLAGS[i];
		i++;
	}
	datas->flags[index++] = '\0';
	datas->flagslen = index;
}


typedef struct		s_test_funs
{
	void (*init_value_str)(t_test_data *);
	void (*init_value)(t_test_data *);
	int (*test)(t_test_data *);
	void (*inc_value)(t_test_data *);
	int (*printf_w_value)(t_test_data *, int (*)(const char*, ...));
	int (*printf_p_value)(t_test_data *, int (*)(const char*, ...));
	int (*printf_w_p_value)(t_test_data *, int (*)(const char*, ...));
	int (*printf_value)(t_test_data *, int (*)(const char*, ...));
}					t_test_funs;


void init_value_str_d(t_test_data * datas)
{
	datas->str_value = ft_itoa(datas->d);
	datas->valuelen = ft_strlen(datas->str_value);
}

void init_d(t_test_data *datas){
	datas->d = min;
}

int printf_w_d(t_test_data *datas, int (*printf_variant)(const char*, ...)){
	return (printf_variant(datas->buffer, datas->w, datas->d));
}

int printf_p_d(t_test_data *datas, int (*printf_variant)(const char*, ...)){
	return (printf_variant(datas->buffer, datas->p, datas->d));
}

int printf_w_p_d(t_test_data *datas, int (*printf_variant)(const char*, ...)){
	return (printf_variant(datas->buffer, datas->w, datas->p, datas->d));
}

int printf_d(t_test_data *datas, int (*printf_variant)(const char*, ...)){
	return (printf_variant(datas->buffer, datas->d));
}

int test_d(t_test_data *datas){
	return (datas->d <= max) ? 1: 0;
}

void inc_d(t_test_data *datas){
	datas->d++;
}


static const t_test_funs NUMERIC_TESTS = {
	&init_value_str_d, &init_d, &test_d, &inc_d, &printf_w_d,  &printf_p_d,  &printf_w_p_d,  &printf_d
};

void init_value_str_void(t_test_data * datas)
{
	datas->str_value = ft_itoa(datas->p_value);
	datas->valuelen = ft_strlen(datas->str_value);
}

void init_void(t_test_data *datas){
	datas->p_value = NULL;
}

int printf_w_void(t_test_data *datas, int (*printf_variant)(const char*, ...)){
	return (printf_variant(datas->buffer, datas->w, datas->p_value));
}

int printf_p_void(t_test_data *datas, int (*printf_variant)(const char*, ...)){
	return (printf_variant(datas->buffer, datas->p, datas->p_value));
}

int printf_w_p_void(t_test_data *datas, int (*printf_variant)(const char*, ...)){
	return (printf_variant(datas->buffer, datas->w, datas->p, datas->p_value));
}

int printf_void(t_test_data *datas, int (*printf_variant)(const char*, ...)){
	return (printf_variant(datas->buffer, datas->p_value));
}

int test_void(t_test_data *datas){
	return (datas->p_value <= max) ? 1: 0;
}

void inc_void(t_test_data *datas){
	datas->p_value++;
}


static const t_test_funs VOID = {
	&init_value_str_void, &init_void, &test_void, &inc_void, &printf_w_void,  &printf_p_void,  &printf_w_p_void,  &printf_void
};

int printf_test(t_test_data * datas, t_test_funs* test_funs)
{
	datas->flagslen = ft_strlen(datas->flags);
	datas->str_w = ft_itoa(datas->w);
	datas->str_p = ft_itoa(datas->p);
	test_funs->init_value_str(datas);
	datas->wlen = ft_strlen(datas->str_w);
	datas->plen = ft_strlen(datas->str_p);

	int error_count = 0;
	int ret_ft = 0;
	int ret = 0;
	fill_buffer(datas, datas->str_w, datas->wlen, datas->str_p, datas->plen, 1);
	fill_info(datas);

	ret = test_funs->printf_value(datas, &printf);
	fflush(stdout);
	ret = test_funs->printf_value(datas, &ft_printf);
	printf("%s\n", datas->info);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	fill_buffer(datas, "*", 1, datas->str_p, datas->plen, 1);
	fill_info(datas);

	ret = test_funs->printf_w_value(datas, &printf);
	fflush(stdout);
	ret = test_funs->printf_w_value(datas, &ft_printf);
	printf("%s\n", datas->info);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	fill_buffer(datas, datas->str_w, datas->wlen, "*", 1, 1);
	fill_info(datas);
	
	ret = test_funs->printf_p_value(datas, &printf);
	fflush(stdout);
	ret = test_funs->printf_p_value(datas, &ft_printf);
	printf("%s\n", datas->info);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	fill_buffer(datas, "*", 1,"*", 1, 1);
	fill_info(datas);
	
	ret = test_funs->printf_w_p_value(datas, &printf);
	fflush(stdout);
	ret = test_funs->printf_w_p_value(datas, &ft_printf);
	printf("%s\n", datas->info);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	fill_buffer(datas, "*", 1,"", 0, 1);
	fill_info(datas);
	
	ret = test_funs->printf_w_value(datas, &printf);
	fflush(stdout);
	ret = test_funs->printf_w_value(datas, &ft_printf);
	printf("%s\n", datas->info);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	fill_buffer(datas, datas->str_w, datas->wlen,"", 0, 1);
	fill_info(datas);
	
	ret = test_funs->printf_value(datas, &printf);
	fflush(stdout);
	ret = test_funs->printf_value(datas, &ft_printf);
	printf("%s\n", datas->info);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	fill_buffer(datas, "*", 1,"", 0, 0);
	fill_info(datas);
	
	ret = test_funs->printf_w_value(datas, &printf);
	fflush(stdout);
	ret = test_funs->printf_w_value(datas, &ft_printf);
	printf("%s\n", datas->info);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	fill_buffer(datas, datas->str_w, datas->wlen,"", 0, 0);
	fill_info(datas);
	
	ret = test_funs->printf_value(datas, &printf);
	fflush(stdout);
	ret = test_funs->printf_value(datas, &ft_printf);
	printf("%s\n", datas->info);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	fill_buffer(datas, "", 0, "*", 1, 1);
	fill_info(datas);
	
	ret = test_funs->printf_p_value(datas, &printf);
	fflush(stdout);
	ret = test_funs->printf_p_value(datas, &ft_printf);
	printf("%s\n", datas->info);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	fill_buffer(datas, "", 0, datas->str_p, datas->plen, 1);
	fill_info(datas);
	
	ret = test_funs->printf_value(datas, &printf);
	fflush(stdout);
	ret = test_funs->printf_value(datas, &ft_printf);
	printf("%s\n", datas->info);
	fflush(stdout);
	error_count = (ret == ret_ft) ? 0: 1; 

	free(datas->str_w);
	free(datas->str_p);
	free(datas->str_value);
	return error_count;
}

int d_filter(t_test_data *datas, t_test_funs* test_funs)
{
	int ret = 0;
	int ret_cumul = 0;
	test_funs->init_value(datas);
	while (test_funs->test(datas))
	{	
		set_flags(datas);
		ret = printf_test(datas, test_funs);
		if(ret != 0)
		{
			//fprintf(stderr, "Error encountered in return values, stopping now, look test for feedback\n");
		}
		test_funs->inc_value(datas);
		ret_cumul += ret;
	}
	return ret_cumul;
}

int p_filter(t_test_data *datas, t_test_funs* test_funs)
{
	int ret = 0;
	int ret_cumul = 0;
	datas->p = min;
	while (datas->p <= max)
	{
		ret = d_filter(datas, test_funs);
		if(ret != 0)
		{
			//silent
		}
		datas->p++;
		ret_cumul += ret;
	}
	return ret_cumul;
}

int w_filter(t_test_data *datas, t_test_funs* test_funs)
{
	int ret = 0;
	int ret_cumul = 0;
	datas->w = min;
	while (datas->w <= max)
	{		
		if(p_filter(datas, test_funs) != 0)
		{
			//silent
		}
		datas->w++;
		ret_cumul += ret;
	}
	return ret_cumul;
}
void fill_convert(char convert_c, t_test_data *datas)
{
	int len = 0;
	datas->convert[len++] = convert_c ;
	datas->convert[len++] = '|';
	datas->convert[len++] = '\n';
	datas->convert[len++] = '\0';
	datas->convertlen = len;

}

void print_flags(char * id, int current_flag, int top_flag, t_test_data *datas){
	fprintf(stderr, "FLAGS::%s:\t:%d::%d::%d\t[", id, datas->flagslen, current_flag, top_flag);
	int i = 0;
	while(i < NBR_FLAGS)
		fprintf(stderr,"%d, ", datas->active_flags>> i++ & 1);
	fprintf(stderr,"]\n");
	fflush(stderr);
}

void testeur(char convert_c, t_test_data *datas, t_test_funs* test_funs)
{
	fill_convert(convert_c, datas);

	int top_flag = NBR_FLAGS;
	int current_flag = 0;
	datas->active_flags = 0;
	current_flag = 0;
	while(datas->active_flags < 16){

		if(w_filter(datas, test_funs) != 0)
		{
		 	//silent
		}
		datas->active_flags++;
	}
}


void printf_unit_test(char letter, int w, int p, void * p_value, int d, t_test_funs * test_funs, t_test_data * datas, char* flags, int flagslen)
{
	fill_convert(letter, datas);
	ft_strlcpy(datas->flags,flags, 30);
	datas->flagslen = flagslen;
	datas->w = w;
	datas->p = p;
	datas->p_value = p_value;
	datas->d = d;
	printf_test(datas, test_funs);
}


#include <stdarg.h>

#define PRINT ft_printf
#define BPRINT(x, ...) PRINT("\"%s\" // 1st '*' = %d, 2nd '*' = %d\n", x, a, b)
int main(int argc, const char * argv[])
{
    (void)argc;
    (void)argv;

	t_test_data datas;
	datas.d = 0;
	datas.p = 0;
	datas.w = 0;
	datas.str_value = NULL;
	datas.str_p = NULL;
	datas.str_w = NULL;
	datas.valuelen = 0;
	datas.plen = 0;
	datas.wlen = 0;
	datas.convertlen = 0;
	datas.infolen = 0;
	datas.bufferlen = 0;
	datas.flagslen = 0;
	datas.flags[0] = '\0';

	// testeur('x', &datas, &NUMERIC_TESTS);
	// testeur('X', &datas, &NUMERIC_TESTS);
	// testeur('d', &datas, &NUMERIC_TESTS);
	testeur('u', &datas, &NUMERIC_TESTS);
	// testeur('i', &datas, &NUMERIC_TESTS);
	// testeur('c', &datas, &NUMERIC_TESTS);
	// testeur('p', &datas, &VOID);


	// //|%#-6.*x|-6:-2:1
	// // printf_unit_test('x', -6, -2, 1, 1, &NUMERIC_TESTS, &datas, "#", 1);
	// // printf_unit_test('p', 3, 0, 0, 0, &VOID, &datas, "", 1);
	// // printf_unit_test('p', 3, 0, 0, 0, &VOID, &datas, "+", 1);


	// int		a = -4;
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

	// // int nbr = 0;
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("Simple input test"));
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j)); //T2
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c, e, d)); //T3
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d)); //T4
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c, e, d)); //T5
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c, e, d)); //T6
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c, e, d)); //T7
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c, e, d)); //T8
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%6i, %6d, %6d, %6d, %6d, %6d, %6d, %6d", i, j, k, l, m, c, e, d)); //T9
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%7i, %7d, %7d, %7d, %7d, %7d, %7d, %7d", i, j, k, l, m, c, e, d)); //T10
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%8i, %8d, %8d, %8d, %8d, %8d, %8d, %8d", i, j, k, l, m, c, e, d)); //T11
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d)); //T12
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d", i, j, k, l, m, c, e, d)); //T13
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d", i, j, k, l, m, c, e, d)); //T14
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d", i, j, k, l, m, c, e, d)); //T15
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d", i, j, k, l, m, c, e, d)); //T16
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c, e, d)); //T17
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c, e, d)); //T18
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-i, %-d, %-d, %-d, %-d, %-d, %-d, %-d", i, j, k, l, m, c, e, d)); //T19
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%.i, %.d, %.d, %.d, %.d, %.d, %.d, %.d", i, j, k, l, m, c, e, d)); //T20
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d", i, j, k, l, m, c, e, d)); //T21
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%00i, %00d, %00d, %00d, %00d, %00d, %00d, %00d", i, j, k, l, m, c, e, d)); //T22
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c, e, d)); //T23
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d", i, j, k, l, m, c, e, d)); //T24
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%1.1i, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d", i, j, k, l, m, c, e, d)); //T25
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d", i, j, k, l, m, c, e, d)); //T26
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d", i, j, k, l, m, c, e, d)); //T27
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1d, %-1d", i, j, k, l, m, c, e, d)); //T28
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-.1i, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d", i, j, k, l, m, c, e, d)); //T29
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d", i, j, k, l, m, c, e, d)); //T30
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d", i, j, k, l, m, c, e, d)); //T31
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d", i, j, k, l, m, c, e, d)); //T32
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d", i, j, k, l, m, c, e, d)); //T33
	// // while (a < 5) //T34-69
	// // {
	// // 	printf("Test nbr:%d\n", nbr++);
	// // 	PRINT(" --- Return : %d\n", PRINT("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// // 	printf("Test nbr:%d\n", nbr++);
	// // 	PRINT(" --- Return : %d\n", PRINT("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// // 	printf("Test nbr:%d\n", nbr++);
	// // 	PRINT(" --- Return : %d\n", PRINT("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// // 	printf("Test nbr:%d\n", nbr++);
	// // 	PRINT(" --- Return : %d\n", PRINT("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// // 	a++;
	// // }
	// // a = -2;
	// // while(a < 5) //T70-177
	// // {
	// // 	b = -2;
	// // 	while (b < 5)
	// // 	{
	// // 		printf("Test nbr:%d\n", nbr++);
	// // 		PRINT(" --- Return : %d\n", PRINT("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// // 		printf("Test nbr:%d\n", nbr++);
	// // 		PRINT(" --- Return : %d\n", PRINT("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// // 		printf("Test nbr:%d\n", nbr++);
	// // 		PRINT(" --- Return : %d\n", PRINT("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	// // 		b++;
	// // 	}
	// // 	a++;
	// // }
	// // a = 19;
	// b = 14;
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, -42, a, b, 42, -a, -b, -42, -a, -b, 42, -a, b, -42, -a, b, 42, a, -b, -42, a, -b, 42)); //T178
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%12.12i, %12.12d", -42, 42)); //T179
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%1s, %1s, %1s, %1s, %1s", n, o, p, q, r)); //T180
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%2s, %2s, %2s, %2s, %2s", n, o, p, q, r)); //T181
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%3s, %3s, %3s, %3s, %3s", n, o, p, q, r)); //T182
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%4s, %4s, %4s, %4s, %4s", n, o, p, q, r)); //T183
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%15s, %15s, %15s, %15s, %15s", n, o, p, q, r)); //T184
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%16s, %16s, %16s, %16s, %16s", n, o, p, q, r)); //T185
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%17s, %17s, %17s, %17s, %17s", n, o, p, q, r)); //T186
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%.s, %.s, %.s, %.s, %.s", n, o, p, q, r)); //T186
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%1.s, %1.s, %1.s, %1.s, %1.s", n, o, p, q, r)); //T186
	// // a = -4;
	// // while (a < 5) //T187-213
	// // {
	// // 	printf("Test nbr:%d\n", nbr++);
	// // 	PRINT(" --- Return : %d\n", PRINT("%*s, %*s, %*s, %*s, %*s, %*s, %*s, %*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
	// // 	printf("Test nbr:%d\n", nbr++);
	// // 	PRINT(" --- Return : %d\n", PRINT("%-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
	// // 	printf("Test nbr:%d\n", nbr++);
	// // 	PRINT(" --- Return : %d\n", PRINT("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
	// // 	a++;
	// // }
	// // a = -2;
	// // while(a < 5) //T70-177
	// // {
	// // 	b = -2;
	// // 	while (b < 5)
	// // 	{
	// // 		printf("Test nbr:%d\n", nbr++);
	// // 		PRINT(" --- Return : %d\n", PRINT("%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
	// // 		printf("Test nbr:%d\n", nbr++);
	// // 		PRINT(" --- Return : %d\n", PRINT("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
	// // 		b++;
	// // 	}
	// // 	a++;
	// // }

	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X", i, i, i, j, j, j, k, k, k, l, l, l, m, m, m, c, c, c, d, d, d, e, e, e)); //T214
	// // a = -1;
	// // while (a < 5) //T214-256
	// // {
	// // 	printf("Test nbr1:%d::%d\n", nbr++, a);
	// // 	PRINT(" --- Return : %d\n", PRINT("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// // 	printf("Test nbr2:%d::%d\n", nbr++, a);
	// // 	PRINT(" --- Return : %d\n", PRINT("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// // 	printf("Test nbr3:%d::%d\n", nbr++, a);
	// // 	PRINT(" --- Return : %d\n", PRINT("%-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// // 	printf("Test nbr4:%d::%d\n", nbr++, a);
	// // 	PRINT(" --- Return : %d\n", PRINT("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
	// // 	a++;
	// // }

	// //367, 371, 375
	// b = 5;
	// a = 2;
	// int r1;
	// int r2;
	// int nbr = 0;
	
	// r1 = printf("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X,\n", a, i, a, i, a, i, a, l, a, l, a, l);
	// fflush(stdout);
	// r2 = ft_printf("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X,\n", a, i, a, i, a, i, a, l, a, l, a, l);
	// printf("%d::%d[%d]  a:%d i:%d l:%d c:%d\n", r1, r2, nbr++, a, i, l, c);
	// fflush(stdout);

	// a = 3;
	// r1 = printf("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X,, %0*u, %0*x, %0*X,\n", a, i, a, i, a, i, a, l, a, l, a, l, a, c, a, c, a, c);
	// fflush(stdout);
	// r2 = ft_printf("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X,, %0*u, %0*x, %0*X,\n", a, i, a, i, a, i, a, l, a, l, a, l, a, c, a, c, a, c);
	// printf("%d::%d[%d]  a:%d i:%d l:%d c:%d\n", r1, r2, nbr++, a, i, l, c);
	// fflush(stdout);

	// a = 4;
	// r1 = printf("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X,, %0*u, %0*x, %0*X,\n", a, i, a, i, a, i, a, l, a, l, a, l, a, c, a, c, a, c);
	// fflush(stdout);
	// r2 = ft_printf("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X,, %0*u, %0*x, %0*X,\n", a, i, a, i, a, i, a, l, a, l, a, l, a, c, a, c, a, c);
	// printf("%d::%d[%d]  a:%d i:%d l:%d c:%d\n", r1, r2, nbr++, a, i, l, c);
	// fflush(stdout);

	
	// // a = -1;
	// // while(a < 5) //T257-346
	// // {
	// // 	b = -1;
	// // 	while (b < 5)
	// // 	{
	// // 		printf("Test nbr:%d\n", nbr++);
	// // 		PRINT(" --- Return : %d\n", PRINT("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
	// // 		printf("Test nbr:%d\n", nbr++);
	// // 		PRINT(" --- Return : %d\n", PRINT("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
	// // 		printf("Test nbr:%d\n", nbr++);
	// // 		PRINT(" --- Return : %d\n", PRINT("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
	// // 		b++;
	// // 	}
	// // 	a++;
	// // }
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0)); //T347
	// // a = 8;
	// // while (a < 12) //
	// // {
	// // 	printf("Test nbr:%d\n", nbr++);
	// // 	PRINT(" --- Return : %d\n", PRINT("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
	// // 	printf("Test nbr:%d\n", nbr++);
	// // 	PRINT(" --- Return : %d\n", PRINT("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
	// // 	a++;
	// // }
	// // a = f;
	// // b = g;
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c));
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));

	// // a = 12;
	// // b = 18;
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c));
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], -a, p[0], -a, q[0], -a, r[0], -a, c));
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], q[0], a, q[0], a, p[0], a, p[0], a, c));
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%c,  %-c, %1c, %*c,  %-*c,  %*c", -12, -1, -255, a, -12, a, -1, a, -255));
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%%, \t, \\, \", \', +"));
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i));
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i));
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j));
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, l, a, l, a, l, a, l, a, l));
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%i, %d, %d, %d, %d, %d, %u, %x, %X", 0, 0, 0, 0, 0, 0, 0, 0, 0));
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%*i, %*d, %*d, %*d, %*d, %*d, %*u, %*x, %*X", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0));
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
	// // // ^ Theoriquement un comportement indefini mais testé par la moulinette
    // // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT("(null)"));
	// // printf("Test nbr:%d\n", nbr++);
	// // PRINT(" --- Return : %d\n", PRINT(""));
}