/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <sdummett@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 06:58:14 by stone             #+#    #+#             */
/*   Updated: 2021/07/06 23:56:54 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	sizeof_new(unsigned long nb)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

static char	*create_address(unsigned long nb)
{
	char	*new;
	char	*hexbase;
	int		len;

	hexbase = "0123456789abcdef";
	len = sizeof_new(nb) + 2;
	new = (char *)malloc(sizeof(char) * len + 1);
	new[0] = '0';
	new[1] = 'x';
	if (nb == 0)
		new[2] = '0';
	new[len] = '\0';
	while (nb)
	{
		new[len - 1] = *(hexbase + nb % 16);
		nb = nb / 16;
		len--;
	}
	return (new);
}

void	pointer_handler(char **format, va_list var, int *ptf_ret)
{
	t_flag_attribs	*flag;
	char			*str;
	int				len;

	len = 0;
	flag = format_parser(format, var);
	str = create_address(va_arg(var, unsigned long));
	if (flag->precision > 0)
		str = padding_handler(str, flag->padding, flag->precision, \
				flag->prec_is_dot);
	if (flag->padding > 0 && flag->precision == 0)
		str = padding_handler(str, flag->padding, flag->precision, \
				flag->prec_is_dot);
	else if (flag->padding > 0 && flag->precision != 0)
		flag->width = flag->padding;
	if (flag->width != 0)
		str = width_handler(str, flag->width);
	count_and_display(format, str, 'p', ptf_ret);
	free(str);
	free(flag);
}
