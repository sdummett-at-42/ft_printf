/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 02:24:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/30 22:34:49 by sdummett         ###   ########.fr       */
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
*/


static void	ft_putstr_with_width(char *fill, char *str, int width, int side)
{
	int len;

	len = ft_strlen(str);
	len = ft_strlen(str);
	if (width != -1)
		width = width - len;
	if (width > 0)
	{
		if (side == 0)
		{
			while (width)
			{
				ft_putchar(*fill);
				fill++;
				width--;
			}
		}
		write(1, str, ft_strlen(str));
		if (side == 1)
		{
			while (width)
			{
				ft_putchar(*fill);
				fill++;
				width--;
			}
		}
	}
	else
	{
		ft_putstr(str);
	}
}
static void	shift_format(char **format)
{
	if (**format == '*')
		(*format)++;
	else if (**format >= '0' && **format <= '9')
	{
		while (**format >= '0' && **format <= '9')
			(*format)++;
	}
}
static char	*width_flag(char **format, va_list var, int *side, int *len)
{
	int nb;
	char *str;

	*side = 0;
	nb = 0;
	if (**format == '-')
	{
		*side = 1;
		(*format)++;
	}
	if (**format <= '9' && **format >= '0')
	{
		nb = nb + ft_atoi(*format);
		*len = nb;
		(*format)++;
	}
	else if (**format == '*')
	{
		nb = va_arg(var, int);
		*len = nb;
		(*format)++;
	}
	if (nb < 1)
	{
		*side = -1;
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * nb + 1);
	str[nb] = '\0';
	while (nb != 0)
	{
		nb--;
		str[nb] = ' ';
	}
	return (str);
}
static int precision_flag(char **format, va_list var)
{
	int nb;

	nb = 0;
	(*format)++;
	if (**format <= '9' && **format >= '0')
	{
		nb = nb + ft_atoi(*format);
		(*format)++;
	}
	else if (**format == '*')
	{
		nb = va_arg(var, int);
		(*format)++;
	}
	return (nb);
}
static void	ft_putstr_with_precision(char *str, int precision)
{
	int len;

	len = ft_strlen(str);
	precision = precision - len;
	if (precision < 0)
		precision = precision * -1;
	if (precision > 0)
	{
		printf("if | precision = %d\n", precision);
		while (precision)
		{
			write(1, "0", 1);
			precision--;
		}
		write(1, str, len);
	}
	else
	{
		printf("else | precision = %d\n", precision);

		write(1, str, len);
	}
	/*
	if (precision > 0)
	{
		if (precision < len)
			write(1, str, precision);
		else
			write(1, str, len);
	}
	if (precision == -1)
		write(1, str, len);
		*/
}

void	integer_handler(char **format, va_list var)
{
	char *str;
	int nb;
	int	side;
	int len = 0;

	if (**format == 'd')
	{
		str = ft_itoa(va_arg(var, int));
		ft_putstr(str);
		(*format)++;
		return ;
	}
	while (**format != 'd')
	{
		if (**format == '.')
		{
			nb = precision_flag(format, var);

			shift_format(format);
			ft_putstr_with_precision(ft_itoa(va_arg(var, int)), nb);
			while (**format != 'd')
				(*format)++;
			(*format)++;
			return ;
		}
		else if ((**format >= '0' && **format <= '9') || **format == '-' || **format == '*')
		{
			str = width_flag(format, var, &side, &len);
			shift_format(format);
			ft_putstr_with_width(str, ft_itoa(va_arg(var, int)), len, side);
			while (**format != 'd')
				(*format)++;
			(*format)++;
			return ;
		}
	}
}
