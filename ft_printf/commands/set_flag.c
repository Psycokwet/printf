/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:39:30 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/02 20:02:20 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_printf.h"

int set_flag(const char *code, t_data *datas){
    int i = MAX_FLAG_OPT;

    while (--i >= 0)
	{
        if (ft_strncmp(FLAGS[i].code.str, code, FLAGS[i].code.size) == 0)
		{
            datas->cursor += FLAGS[i].code.size;
            FLAGS[i].prepare_flag(datas);
            return (EXIT_CODE_FOUND);
        }
    }
    return (EXIT_CODE_NOT_FOUND);
}
