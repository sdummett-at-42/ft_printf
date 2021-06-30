/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 02:24:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/30 19:01:47 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

/*
void	ft_putnbr(long long int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(nb + 48);	
}

void	decimal_handler(char **format, va_list var)
{
	char *str;
	int nb;
	int	side;
	int len = 0;

	if (**format == 'd')
	{
		ft_putnbr(va_arg(var, int));
		(*format)++;
		return ;
	}

	while (**format != 'd')
	{
		if (**format == '.')
		{
			nb = precision_flag(format, var);
			shift_format(format);
			ft_putstr_with_precision(va_arg(var, char *), nb);
			while (**format != 'd')
				(*format)++;
			(*format)++;
			return ;
		}
		else if ((**format >= '1' && **format <= '9') || **format == '-' || **format == '*')
		{
			str = width_flag(format, var, &side, &len);
			shift_format(format);
			ft_putstr_with_width(str, va_arg(var, char *), len, side);
			while (**format != 'd')
				(*format)++;
			(*format)++;
			return ;
		}
	}
}
*/
