/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 12:09:31 by sdummett          #+#    #+#             */
/*   Updated: 2022/02/11 17:53:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
 *	percent_printer() checks all the flags raised and call the right
 *	functions in order to do right conversions, then print it.
*/

void	percent_printer(char **fmt, va_list var, int *ptf_ret)
{
	char		*str;
	t_attribs	*flag;

	flag = fmt_parser(fmt, var);
	str = ft_strdup("%");
	if (flag->precision > 0 || flag->prec_is_zero == 1)
		str = precision_conversion(str, flag->precision);
	if (flag->padding > 0)
		str = padding_conversion(str, flag->padding, flag->precision, \
				flag->prec_is_zero);
	if (flag->width != 0)
		str = width_conversion(str, flag->width);
	count_and_print(fmt, str, '%', ptf_ret);
	free(str);
	free(flag);
}
