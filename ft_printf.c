/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 09:49:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/27 02:36:54 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_format(char **format, va_list var) //envoyer la va_list
{
	int ret;

//	i = 0;
	while (**format != '\0')
	{
		ret = check_specifier(format, var);
		if (ret == 42)
			return ;
	}
}

int ft_printf(const char *format, ...)
{
//	int	i;
	va_list	vars;
	va_start(vars, format);
	
//	i = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			check_format((char **)&format, vars);
		}
		else
		{
			ft_putchar(*format);
			format++;
		}
	}
	va_end(vars);
	return (42);
}

