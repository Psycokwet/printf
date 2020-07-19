/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_correct_diese.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/19 11:23:00 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void set_correct_diese(t_data *datas)
{
    printf("ICI ??? [%u] [%d]\n", datas->value_ui, datas->active_flags & FT_PF_FLAG_DIESE? 1: 0);
    fflush(stdout);
    if(datas->value_ui == 0 && datas->active_flags & FT_PF_FLAG_DIESE){
        printf("ICI OUI\n");
        fflush(stdout);
        datas->active_flags -= FT_PF_FLAG_DIESE;
    }
}
