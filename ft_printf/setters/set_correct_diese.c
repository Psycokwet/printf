/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_correct_diese.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/22 17:37:50 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void set_correct_diese(t_data *datas)
{
    if(datas->value_ui == 0 && datas->active_flags & FT_PF_FLAG_DIESE)
        datas->unauthorized_flags |= FT_PF_FLAG_DIESE;
    set_diese_cost(datas);
}
