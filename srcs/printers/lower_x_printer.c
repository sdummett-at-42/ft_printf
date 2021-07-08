/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_x_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 02:24:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/08 22:40:00 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	lower_x_printer(char **fmt, va_list var, int *ptf_ret)
{
	char		*str;
	t_attribs	*flag;

	flag = fmt_parser(fmt, var);
	if (flag->prec_is_dot == 0 && flag->padding < 0)
		flag->width = flag->padding;
	str = uitohex_low(va_arg(var, unsigned int));
	str = check_if_eq_zero(str, flag->prec_is_dot);
	if (flag->precision > 0)
		str = precision_conversion(str, flag->precision);
	if (flag->prefix == 1)
		str = x_prefix_conversion(str, 'x');
	if (flag->width != 0)
		str = width_conversion(str, flag->width);
	if (flag->padding > 0 || flag->prec_is_dot == 1)
		str = padding_conversion(str, flag->padding, \
				flag->precision, flag->prec_is_dot);
	count_and_print(fmt, str, 'x', ptf_ret);
	free(flag);
	free(str);
}
