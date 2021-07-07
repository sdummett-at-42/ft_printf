/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 09:49:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/07 02:15:58 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_fmt(char *fmt, int *i, int *ptf_ret)
{
	write(1, fmt - *i, *i);
	*ptf_ret = *ptf_ret + *i;
	*i = 0;
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	var;

	i = 0;
	len = 0;
	va_start(var, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			call_handler(search_specifier((char **)&format), \
					(char **)&format, var, &len);
		}
		else
		{
			i++;
			format++;
			if (*format == '%' || *format == '\0')
				put_fmt((char *)format, &i, &len);
		}
	}
	va_end(var);
	return (len);
}
