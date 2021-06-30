/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 05:12:17 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/30 04:38:42 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"
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
static long int conv_nb(long int nb)
{
	long int ref;

	ref = 4294967295;
	nb = (nb * -1) - 1;
	ref = ref - nb;
	return (ref);
}
static int	len_str(long int nb)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}
char	*create_hexa_string(long int nb)
{
	char	*str;
	char	*hexbase;
	int		len;

	hexbase = "0123456789abcdef";
	if (nb < 0)
		nb = conv_nb(nb);
	len = len_str(nb);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (nb == 0)
		str[0] = '0';
	str[len] = 0;
	while (nb)
	{
		str[len - 1] = *(hexbase + nb % 16);
		nb = nb / 16;
		len--;
	}
	return (str);	
	//ft_putstr(str);
	//free(str);
}

static void	ft_putaddr_with_width(char *fill, void *addr, int width, int side)
{
	int len;
	char *str;

	str = create_hexa_string(*(long int *)&addr);
	len = ft_strlen(str) + 2;
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
		ft_putstr("0x");
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
		ft_putstr("0x");
		ft_putstr(str);
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
		if (nb < 0)
		{
			nb = nb * -1;
			if (*side == 0)
				*side = 1;
		}
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

///static void	ft_putaddr_with_width(char *fill, void *addr, int width, int side)
void	pointer_handler(char **format, va_list var)
{
	int side;
	int len = 0;
	char *str;

	if ((**format >= '1' && **format <= '9') || **format == '-' || **format == '*')
	{
		str = width_flag(format, var, &side, &len);
		shift_format(format);
		ft_putaddr_with_width(str, va_arg(var, void *), len, side);
		while (**format != 'p')
			(*format)++;
		(*format)++;
		return ;
	}
	else
	{
		ft_putaddr_with_width(NULL, va_arg(var, void *), 0, -1);
		(*format)++;
	}
}
