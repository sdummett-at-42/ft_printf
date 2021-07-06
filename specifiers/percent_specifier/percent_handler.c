/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 12:09:31 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/06 23:46:22 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	percent_handler(char **format, va_list var, int *ptf_ret)
{
	int				len;
	char			*str;
	t_flag_attribs	*flag;

	len = 0;
	flag = format_parser(format, var);
	str = ft_strdup("%");
	if (flag->precision > 0 || flag->prec_is_dot == 1)
		str = precision_handler(str, flag->precision);
	if (flag->padding > 0)
		str = padding_handler(str, flag->padding, flag->precision, \
				flag->prec_is_dot);
	if (flag->width != 0)
		str = width_handler(str, flag->width);
	count_and_display(format, str, '%', ptf_ret);
	free(str);
	free(flag);
}
