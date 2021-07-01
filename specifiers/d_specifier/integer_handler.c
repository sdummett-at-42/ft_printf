/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 02:24:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/01 02:47:35 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"


static t_flag_attribs *struct_initializer(void)
{
	t_flag_attribs *new;

	new = (t_flag_attribs *)malloc(sizeof(t_flag_attribs) * 1);
	new->precision = 0;
	new->width = 0;
	new->zero = 0;
	return (new);
}

static t_flag_attribs *integer_parser(char **format, va_list var)
{
	int i;
	int neg;
	t_flag_attribs *spec_infos;

	spec_infos = struct_initializer();
	i = 0;
	neg = 1;
	if (((*format)[i] >= '0' && (*format)[i] <= '9') || (*format)[i] == '-' || \
			(*format)[i] == '*')
	{
		if ((*format)[i] == '-')
		{
			neg = -1;
			i++;
		}
		if ((*format)[i] == '*')
		{
			spec_infos->width = va_arg(var, int) * neg;
			i++;
		}
		else
			spec_infos->width = ft_atoi(&(*format)[i]) * neg;
		while (((*format)[i] >= '0' && (*format)[i] <= '9') || (*format)[i] == '-')
			i++;
	}
	if ((*format)[i] == '.')
	{
		i++;
		if ((*format)[i] == '*')
			spec_infos->precision = va_arg(var, int);
		else
			spec_infos->precision = ft_atoi(&(*format)[i]);		
		while ((*format)[i] >= '0' && (*format)[i] <= '9')
			i++;
	}
	return (spec_infos);
}

static char	*add_zero(char *str, int precision, int len)
{
	int i;
	int minus;
	char *new;

	minus = -1;
	precision = precision - len;
	i = 0;
	if (str[i] == '-')
	{
		precision = precision + 1;
		new = (char *)malloc(sizeof(char) * len + precision + 1);
		new[i] = '-';
		str++;
		i++;
	}
	else
		new = (char *)malloc(sizeof(char) * len + precision + 1);
	while (precision != 0)
	{
		new[i] = '0';
		i++;
		precision--;
	}
	len = 0;
	while (str[len] != '\0')
	{
		new[i] = str[len];
		i++;
		len++;
	}
	new[i] = '\0';
	return (new);
}


static int insert_spaces(char *str, int width)
{
	int i;

	i = 0;

	while (width != 0)
	{
		str[i] = ' ';
		width--;
		i++;
	}
	str[i] = '\0';
	return (i);
}
static char *add_space(char *str, int width, int len)
{
	char *new;
	int i;

	if (width != 0)
	{

		i = 0;
		if (width > 0)
		{	
			width = width - len;
			if (width < 0)
				return (str);
			new = (char *)malloc(sizeof(char) + len + width + 1);
			i = insert_spaces(new, width);
		}
		else
			new = (char *)malloc(sizeof(char) + len + (width * -1) + 1);
		len = 0;
		while (str[len] != '\0')
		{
			new[i] = str[len];
			i++;
			len++;
		}
		if (width < 0)
		{	
			width = (width * -1) - len;
			return (str);
			i = insert_spaces(new + i, width);
		}
		new[i] = '\0';
		free(str);
		return (new);
	}
	return (str);
}

void	integer_handler(char **format, va_list var)
{
	t_flag_attribs *spec_infos;
	char *str;
	int len = 0;

	spec_infos = integer_parser(format, var);
	str = ft_itoa(va_arg(var, int));
	if (spec_infos->precision > 0)
	{
		len = ft_strlen(str);
		str = add_zero(str, spec_infos->precision, len);
	}
	if (spec_infos->width != 0)
	{
		len = ft_strlen(str);
		str = add_space(str, spec_infos->width, len);
	}
	// BUS ERROR HERE
	while (**format != 'd' && **format != 'i')
		(*format)++;
	(*format)++;
	write(1, str, ft_strlen(str));
}
