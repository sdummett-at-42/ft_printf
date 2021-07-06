/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 09:49:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/06 13:42:31 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		len;
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
			write(1, &(*format), 1);
			len++;
			format++;
		}
	}
	va_end(vars);
	return (len);
}
