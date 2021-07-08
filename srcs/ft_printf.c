/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 09:49:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/08 23:08:01 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 *	While ft_printf doesnt find any '%' it will iterate on the format
 *	string. If it findf a '%' it will call the printer function associated with
 *	the specifer given.
 */

static void	print_fmt(char *fmt, int *i, int *ptf_ret)
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
			call_printer(search_specifier((char **)&format), \
					(char **)&format, var, &len);
		}
		else
		{
			i++;
			format++;
			if (*format == '%' || *format == '\0')
				print_fmt((char *)format, &i, &len);
		}
	}
	va_end(var);
	return (len);
}
