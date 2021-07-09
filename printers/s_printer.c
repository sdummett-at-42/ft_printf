/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 02:19:32 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/09 15:31:18 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*create_str(char *str)
{
	if (str == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

/*
 *	resize_str() resize the string in order to match the precision given.
*/

static char	*resize_str(char *str, int precision)
{
	int		len;
	char	*new;

	len = ft_strlen(str);
	if (precision >= len)
		return (str);
	new = (char *)malloc(sizeof(char) * precision + 1);
	if (new == NULL)
		return (NULL);
	new[precision] = '\0';
	while (precision > 0)
	{
		precision--;
		new[precision] = str[precision];
	}
	free(str);
	return (new);
}

/*
 *	s_printer() checks all the flags raised and call the right
 *	functions in order to do right conversions, then print it.
*/

void	s_printer(char **fmt, va_list var, int *ptf_ret)
{
	t_attribs	*flag;
	char		*str;
	int			len;

	len = 0;
	flag = fmt_parser(fmt, var);
	str = create_str(va_arg(var, char *));
	if (flag->precision > 0 || flag->prec_is_zero == 1)
		str = resize_str(str, flag->precision);
	if (flag->padding > 0 && flag->precision > 0)
		flag->width = flag->padding;
	if (flag->width != 0)
		str = width_conversion(str, flag->width);
	count_and_print(fmt, str, 's', ptf_ret);
	free(str);
	free(flag);
}
