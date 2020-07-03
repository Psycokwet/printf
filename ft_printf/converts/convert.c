/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:00:02 by scarboni          #+#    #+#             */
/*   Updated: 2020/07/03 09:25:06 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int convert(t_data *datas, int max_setter, const t_setter *setter, int max_writer, const t_write *writer)
{
    int ret_writer;
    int i ;
    
    i = max_setter;
    if(setter)
        while (i--)
            setter[i].setter(datas);

    i = max_writer;
    if(writer)
        while (i--)
        { 
            if (!((datas->active_flags & writer[i].flags_concerned) == writer[i].flags_awaited))
                continue;
            ret_writer = writer[i].write(datas);
            if (ret_writer < EXIT_SUCCESS)
                return (-EXIT_FAILURE);
            datas->written_count += ret_writer;
        }
    //datas->written_count += ret_read + padding;
    return (EXIT_CODE_END_FOUND);
}
