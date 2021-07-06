/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 02:24:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/06 14:41:46 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static t_flag_attribs	*integer_parser(char **format, va_list var)
{
	int				i;
	int				neg;
	t_flag_attribs	*spec_infos;

	spec_infos = struct_init();
	i = 0;
	neg = 1;
	if ((*format)[i] == '0')
	{
		i++;
		if ((*format)[i] == '-')
			spec_infos->padding = 0;
		else if ((*format)[i] == '*')
			spec_infos->padding = va_arg(var, int);
		else
			spec_infos->padding = ft_atoi(&(*format)[i]);
		while (((*format)[i] >= '0' && (*format)[i] <= '9') || \
				(*format)[i] == '*')
			i++;
	}
	if (((*format)[i] >= '1' && (*format)[i] <= '9') || \
			(*format)[i] == '-' || (*format)[i] == '*')
	{
		if ((*format)[i] == '-')
		{
			neg = -1;
			i++;
		}
		while ((*format)[i] == '0')
			i++;
		while ((*format)[i] == '-')
			i++;
		if ((*format)[i] == '*')
		{
			spec_infos->width = va_arg(var, int);
			if (neg == -1 && spec_infos->width > 0)
				spec_infos->width = spec_infos->width * -1;
			i++;
		}
		else
			spec_infos->width = ft_atoi(&(*format)[i]) * neg;
		while (((*format)[i] >= '0' && (*format)[i] <= '9') || \
				(*format)[i] == '-')
			i++;
	}
	if ((*format)[i] == '.')
	{
		i++;
		if ((*format)[i] == '*')
		{	
			spec_infos->precision = va_arg(var, int);
		}
		else if ((*format)[i] >= '0' && (*format)[i] <= '9')
			spec_infos->precision = ft_atoi(&(*format)[i]);
		if (spec_infos->precision == 0)
			spec_infos->prec_is_dot = 1;
		while ((*format)[i] >= '0' && (*format)[i] <= '9')
			i++;
	}
	return (spec_infos);
}

void	integer_handler(char **format, va_list var, int *ptf_ret)
{
	char			*str;
	t_flag_attribs	*flag;

	flag = integer_parser(format, var);
	if (flag->prec_is_dot == 0 && flag->padding < 0)
		flag->width = flag->padding;
	str = ft_itoa(va_arg(var, int));
	str = check_if_eq_zero(str, flag->prec_is_dot);
	if (flag->precision > 0)
		str = precision_handler(str, flag->precision);
	if (flag->width != 0)
		str = width_handler(str, flag->width);
	if (flag->padding > 0 || flag->prec_is_dot == 1)
		str = padding_handler(str, flag->padding, \
				flag->precision, flag->prec_is_dot);
	count_and_display(format, str, 'd', ptf_ret);
	free(flag);
	free(str);
}
