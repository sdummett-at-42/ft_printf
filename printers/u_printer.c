/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 02:24:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/09 14:59:47 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
 *	u_printer() checks all the flags raised and call the right
 *	functions in order to do right conversions, then print it.
*/

void	u_printer(char **fmt, va_list var, int *ptf_ret)
{
	char		*str;
	t_attribs	*flag;

	flag = fmt_parser(fmt, var);
	if (flag->prec_is_zero == 0 && flag->padding < 0)
		flag->width = flag->padding;
	str = uitoa(va_arg(var, int));
	str = check_if_eq_zero(str, flag->prec_is_zero);
	if (flag->precision > 0)
		str = precision_conversion(str, flag->precision);
	if (flag->width != 0)
		str = width_conversion(str, flag->width);
	if (flag->padding > 0 || flag->prec_is_zero == 1)
		str = padding_conversion(str, flag->padding, \
				flag->precision, flag->prec_is_zero);
	count_and_print(fmt, str, 'u', ptf_ret);
	free(flag);
	free(str);
}
