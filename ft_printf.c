/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 09:49:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/02 08:23:33 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int len;
	va_list	vars;

	len = 0;
	va_start(vars, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			call_handler(search_specifier((char **)&format), \
					(char **)&format, vars, &len);
		}
		else
		{
			ft_putchar(*format);
			len++;
			format++;
		}
	}
	va_end(vars);
	return (len);
}

