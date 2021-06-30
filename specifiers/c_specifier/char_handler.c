/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 02:13:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/30 18:33:58 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

/*
 *	Flags 
 *	1 : 0
 *	2 : .
 *	3 : -
*/ 

 void	ft_putchar(char c)
{
	write(1, &c, 1);
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

static char	*zero_flag(char **format, va_list var)
{
	int	nb;
	char *str;

	nb = 0;
	(*format)++;
	if (**format <= '9' && **format >= '0')
	{
		nb = nb + ft_atoi(*format) - 1;
		(*format)++;
	}
	else if (**format == '*')
	{
		nb = va_arg(var, int) - 1;
		(*format)++;
	}
	if (nb < 1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * nb + 1);
	str[nb] = '\0';
	while (nb != 0)
	{
		nb--;
		str[nb] = '0';
	}
	return (str);
}

static char	*width_flag(char **format, va_list var, int *side)
{
	int nb;
	char *str;

	*side = 0;
	nb = 0;
	//(*format)++;
	if (**format == '-')
	{
		*side = 1;
		(*format)++;
	}
	if (**format <= '9' && **format >= '0')
	{
		nb = nb + ft_atoi(*format) - 1;
		(*format)++;
	}
	else if (**format == '*')
	{
		nb = va_arg(var, int) - 1;
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

void	char_handler(char **format, va_list var)
{
	char *str;
	int	side;	
	//(*format)++;
	while (**format != 'c')
	{
		if (**format == '0')
		{
			str = zero_flag(format, var);
			shift_format(format);
			if (str != NULL)
				ft_putstr(str);
			ft_putchar(va_arg(var, int));
			while (**format != 'c')
				(*format)++;
			(*format)++;
			return ;
		}
		else if ((**format >= '1' && **format <= '9') || **format == '-' || **format == '*')
		{
			str = width_flag(format, var, &side);
			shift_format(format);
			if (side == 0)
			{
				ft_putstr(str);
			}
			ft_putchar(va_arg(var, int));
			if (side == 1)
				ft_putstr(str);
			while (**format != 'c')
				(*format)++;
			(*format)++;
			return ;
		}
	}
}

