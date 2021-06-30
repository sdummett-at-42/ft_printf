/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 09:49:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/30 21:09:17 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	vars;

	va_start(vars, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			call_handler(search_specifier((char **)&format), (char **)&format, vars);
			//check_format((char **)&format, vars);
		}
		else
		{
			printf("else ???\n");
			ft_putchar(*format);
			format++;
		}
	}
	va_end(vars);
	return (42);
}

