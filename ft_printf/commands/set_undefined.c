/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_undefined.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:39:30 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/02 19:51:00 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

int set_undefined(const char *code, t_data *datas){
    printf("\nUNDEFINED BEHAVIOR %s\n", code);
    (void)datas;
    return -EXIT_FAILURE;
}
