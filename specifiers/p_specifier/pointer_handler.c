/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <sdummett@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 06:58:14 by stone             #+#    #+#             */
/*   Updated: 2021/07/02 08:56:59 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int	len_str(unsigned long nb)
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

static char	*uitohexlow_addr(unsigned long nb)
{
	char	*str;
	char	*hexbase;
	int		len;

	hexbase = "0123456789abcdef";
	len = len_str(nb) + 2;
	str = (char *)malloc(sizeof(char) * len + 1);
	str[0] = '0';
	str[1] = 'x';
	if (nb == 0)
		str[2] = '0';
	str[len] = '\0';
	//len = len ;
	while (nb)
	{
		str[len - 1] = *(hexbase + nb % 16);
		nb = nb / 16;
		len--;
	}
	return (str);
}

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
	if ((*format)[i] == '0')
	{
		i++;
		if ((*format)[i] == '*')
			spec_infos->zero = va_arg(var, int);
		else
			spec_infos->zero = ft_atoi(&(*format)[i]);
		while ((*format)[i] >= '0' && (*format)[i] <= '9')
			i++;
	}
	if (((*format)[i] >= '1' && (*format)[i] <= '9') || \
			(*format)[i] == '-' || (*format)[i] == '*')
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
		while (((*format)[i] >= '0' && (*format)[i] <= '9') || \
				(*format)[i] == '-')
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

static char	*add_zero(char *str, int width_prec, int len, int flag)
{
	int i;
	int minus;
	char *new;


	if (str[0] == '-' && flag != 1)
	{
		if (width_prec < len)
			return (str);
	}
	else if (width_prec <= len)
	{
		return (str);
	}
	minus = -1;
	width_prec = width_prec - len;
	i = 0;
	if (str[i] == '-')
	{
		if (flag != 1)
			width_prec = width_prec + 1;
		new = (char *)malloc(sizeof(char) * len + width_prec + 1);
		new[i] = '-';
		str++;
		i++;
	}
	else
		new = (char *)malloc(sizeof(char) * len + width_prec + 1);
	while (width_prec != 0)
	{
		new[i] = '0';
		i++;
		width_prec--;
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
	return (i);
}

static char *add_space(char *str, int width, int len)
{
	char *new;
	int i;

	i = 0;
	if (width < 0)
	{
		width = (width * -1) - len;
		if (width < 0)
			return (str);
		new = (char *)malloc(sizeof(char) + len + \
				width + 1);
		len = 0;
		while (str[len] != '\0')
		{
			new[i] = str[len];
			i++;
			len++;
		}
		insert_spaces(new + i, width);
		i = i + width ;
		new[i] = '\0';
		free(str);
		return (new);
	}
	width = width - len;
	if (width < 0)
		return (str);
	new = (char *)malloc(sizeof(char) + len + width + 1);
	i = insert_spaces(new, width);
	len = 0;
	while (str[len] != '\0')
	{
		new[i] = str[len];
		i++;
		len++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

void	pointer_handler(char **format, va_list var, int *ptf_ret)
{
	t_flag_attribs *spec_infos;
	char *str;
	int len = 0;

	spec_infos = integer_parser(format, var);
	str = uitohexlow_addr(va_arg(var, unsigned long));
	if (spec_infos->precision > 0)
	{
		len = ft_strlen(str);
		str = add_zero(str, spec_infos->precision, len, 0);
	}
	if (spec_infos->zero > 0 && spec_infos->precision == 0)
	{
		len = ft_strlen(str);
		str = add_zero(str, spec_infos->zero, len, 1);
	}
	else if (spec_infos->zero > 0 && spec_infos->precision != 0)
		spec_infos->width = spec_infos->zero;
	if (spec_infos->width != 0)
	{
		len = ft_strlen(str);
		str = add_space(str, spec_infos->width, len);
	}
	while (**format != 'p')
		(*format)++;
	(*format)++;
	len = ft_strlen(str);
	*ptf_ret = *ptf_ret + len;
	write(1, str, len);
	free(str);
}

