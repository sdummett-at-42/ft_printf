/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_integer_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 02:24:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/07 01:10:19 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	u_integer_handler(char **fmt, va_list var, int *ptf_ret)
{
	char		*str;
	t_attribs	*flag;

	flag = fmt_parser(fmt, var);
	if (flag->prec_is_dot == 0 && flag->padding < 0)
		flag->width = flag->padding;
	str = ft_uitoa(va_arg(var, int));
	str = check_if_eq_zero(str, flag->prec_is_dot);
	if (flag->precision > 0)
		str = precision_handler(str, flag->precision);
	if (flag->width != 0)
		str = width_handler(str, flag->width);
	if (flag->padding > 0 || flag->prec_is_dot == 1)
		str = padding_handler(str, flag->padding, \
				flag->precision, flag->prec_is_dot);
	count_and_display(fmt, str, 'u', ptf_ret);
	free(flag);
	free(str);
}
