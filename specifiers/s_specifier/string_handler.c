/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 02:19:32 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/30 04:10:28 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

/*
 * precision > 0  -> found precision flag
 * precsion == -1 -> no precision flag found
 */

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

static void	ft_putstr_with_precision(char *str, int precision)
{
	int len;

	len = ft_strlen(str);
	if (precision > 0)
	{
		if (precision < len)
			write(1, str, precision);
		else
			write(1, str, len);
	}
	if (precision == -1)
		write(1, str, len);
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

void	str_handler(char **format, va_list var)
{
	char *str;
	int nb;
	int	side;
	int len = 0;

	if (**format == 's')
	{
		ft_putstr(va_arg(var, char *));
		(*format)++;
		return ;
	}

	while (**format != 's')
	{
		if (**format == '.')
		{
			nb = precision_flag(format, var);
			shift_format(format);
			ft_putstr_with_precision(va_arg(var, char *), nb);
			while (**format != 's')
				(*format)++;
			(*format)++;
			return ;
		}
		else if ((**format >= '1' && **format <= '9') || **format == '-' || **format == '*')
		{
			str = width_flag(format, var, &side, &len);
			shift_format(format);
			ft_putstr_with_width(str, va_arg(var, char *), len, side);
			while (**format != 's')
				(*format)++;
			(*format)++;
			return ;
		}
	}
}
