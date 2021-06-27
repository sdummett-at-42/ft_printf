/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 23:10:31 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/28 00:56:26 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void call_handler(int handler_choice, va_list var)
{
	if (handler_choice == 1)
		ft_putchar(va_arg(var, int));
	else if (handler_choice == 2)
		ft_putstr(va_arg(var, char *));
	else if (handler_choice == 3)
		ft_putaddr(va_arg(var, void *));
	else if (handler_choice == 4)
		ft_putnbr(va_arg(var, int));
	else if (handler_choice == 5)
		ft_putnbr(va_arg(var, unsigned int));
	else if (handler_choice == 6)
	   ft_puthex_low(va_arg(var, int));	// UP ???
	else if (handler_choice == 7)
		ft_putpercent();
}
