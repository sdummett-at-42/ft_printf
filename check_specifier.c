/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 02:30:27 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/27 02:41:37 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_specifier(char **format, va_list var)
{
		if (**format == '%')
			ft_putpercent();
		else if (**format == 'c')
			ft_putchar(va_arg(var, int));
		else if (**format == 's')
			ft_putstr(va_arg(var, char *));
		else if (**format == 'p')
			ft_putaddr(va_arg(var, void *));
		else if (**format == 'd' || **format == 'i')
			ft_putnbr(va_arg(var, int));
		else if (**format == 'u')
			ft_putnbr(va_arg(var, unsigned int));
		else if (**format == 'x')
			ft_puthex_low(va_arg(var, int));
		else if (**format == 'X')
			ft_puthex_up(va_arg(var, int));
		(*format)++;
		return 42;
}
