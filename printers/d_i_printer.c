/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 02:24:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/09 14:59:32 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
 *	plus_prefix_conversion() just add '+' at the beginning of the string
 *	if its value is positive.
*/

static char	*plus_prefix_conversion(char *str)
{
	int		i;
	int		len;
	char	*new;

	if (*str == '-')
		return (str);
	len = ft_strlen(str) + 1;
	new = (char *)malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	new[0] = '+';
	i = 1;
	len = 0;
	while (str[len] != '\0')
	{
		new[i] = str[len];
		len++;
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

/*
 *	blank_conversion() for 'd' and 'i' specifiers, if the value is positive
 *	then it adds ' ' at the beginning of the string.
*/

static char	*blank_conversion(char *str)
{
	int		i;
	int		len;
	char	*new;

	if (*str == '-')
		return (str);
	len = ft_strlen(str) + 1;
	new = (char *)malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	new[0] = ' ';
	i = 1;
	len = 0;
	while (str[len] != '\0')
	{
		new[i] = str[len];
		len++;
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

/*
 *	d_i_printer() checks all the flags raised and call the right
 *	functions in order to do right conversions, then print it.
*/

void	d_i_printer(char **fmt, va_list var, int *ptf_ret)
{
	char		*str;
	t_attribs	*flag;

	flag = fmt_parser(fmt, var);
	if (flag->prec_is_zero == 0 && flag->padding < 0)
		flag->width = flag->padding;
	str = ft_itoa(va_arg(var, int));
	str = check_if_eq_zero(str, flag->prec_is_zero);
	if (flag->precision > 0)
		str = precision_conversion(str, flag->precision);
	if (flag->blank == 1)
		str = blank_conversion(str);
	if (flag->plus_prefix == 1)
		str = plus_prefix_conversion(str);
	if (flag->width != 0)
		str = width_conversion(str, flag->width);
	if (flag->padding > 0 || flag->prec_is_zero == 1)
		str = padding_conversion(str, flag->padding, \
				flag->precision, flag->prec_is_zero);
	count_and_print(fmt, str, 'd', ptf_ret);
	free(flag);
	free(str);
}
