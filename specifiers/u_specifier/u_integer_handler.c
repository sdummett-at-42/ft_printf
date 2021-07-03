/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 02:24:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/03 15:26:57 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"


static t_flag_attribs *struct_initializer(void)
{
	t_flag_attribs *new;

	new = (t_flag_attribs *)malloc(sizeof(t_flag_attribs) * 1);
	new->precision = 0;
	new->prec_is_dot = 0;
	new->width = 0;
	new->padding = 0;
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
			spec_infos->padding = va_arg(var, int);
		else
			spec_infos->padding = ft_atoi(&(*format)[i]);		
		while (((*format)[i] >= '0' && (*format)[i] <= '9') || (*format)[i] == '*')
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
		else if ((*format)[i] >= '0' && (*format)[i] <= '9')
		{
			spec_infos->precision = ft_atoi(&(*format)[i]);		
			if (spec_infos->precision == 0)
				spec_infos->prec_is_dot = 1;
		}
		else
			spec_infos->prec_is_dot = 1;
		while ((*format)[i] >= '0' && (*format)[i] <= '9')
			i++;
	}
	return (spec_infos);
}

static char *pos_prec_handler(char *str, int precision, int len)
{
	int i;
	char *new;

	if (precision <= len)
		return (str);
	new = (char *)malloc(sizeof(char) * precision + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	precision = precision - len;
	while (i < precision)
	{
		new[i] = '0';
		i++;
	}
	len = 0;
	while (str[len] != 0)
	{
		new[i] = str[len];
		i++;
		len++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

static char *neg_prec_handler(char *str, int precision, int len)
{
	int i;
	char *new;

	if (!(precision + 1 >= len))
		return (str);
	new = malloc(sizeof(char) * precision + 2);
	new[0] = '-';
	precision = precision - (len - 1);
	i = 1;
	while (precision != 0)
	{
		new[i] = '0';
		i++;
		precision--;
	}
	precision = 1;
	while (str[precision] != '\0')
	{
		new[i] = str[precision];
		i++;
		precision++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

static char *neg_wid_handler(char *str, int width, int len)
{
	int i;
	char *new;

	if (width <= len)
		return (str);
	new = malloc(sizeof(char) * width + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	while (i != width)
	{
		new[i] = ' ';
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

static char *pos_wid_handler(char *str, int width, int len)
{
	int i;
	char *new;

	if (width <= len)
		return (str);
	new = malloc(sizeof(char) * width + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < (width - len))
	{
		new[i] = ' ';
		i++;
	}
	len = 0;
	while (str[len] != '\0')
	{
		new[i] = str[len];
		i++;
		len++;
	}
	new[i]= '\0';
	free(str);
	return (new);
}

static char *check_str_is_eq_zero(char *str, int dot, int len)
{
	if (len == 1 && str[0] == '0' && dot == 1)
	{
		free(str);
		return (ft_strdup(""));
	}
	return (str);
}

static char *precision_handler(char *str, int precision, int dot)
{
	int len;

	len = ft_strlen(str);
	str = check_str_is_eq_zero(str, dot, len);
	if (str[0] == '-')
		return (neg_prec_handler(str, precision, len));
	else
		return (pos_prec_handler(str, precision, len));
}


static char *width_handler(char *str, int width)
{
	int len;

	len = ft_strlen(str);
	if (width < 0)
		return (neg_wid_handler(str, width * -1, len));
	return (pos_wid_handler(str, width, len));
}

static char *pos_pad_handler(char *str, int padding, int len)
{
	int i;
	char *new;
	
	if (padding <= len)
		return (str);
	new = malloc(sizeof(char) * padding + 1);
	if (new == NULL)
		return (NULL);
	padding = padding - len;
	i = 0;
	while (padding != 0)
	{
		new[i] = '0';
		i++;
		padding--;
	}
	len = 0;
	while (str[len] != '\0')
	{
		new[i] = str[len];
		len++;
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

static char *neg_pad_handler(char *str, int padding, int len)
{
	int i;
	char *new;

	if (padding <= len)
		return (str);
	new = malloc(sizeof(char) * padding + 1);
	if (new == NULL)
		return (NULL);
	new[0] = '-';
	padding = padding - len;
	i = 1;
	while (padding != 0)
	{
		new[i] = '0';
		i++;
		padding--;
	}
	len = 1;
	while (str[len] != '\0')
	{
		new[i] = str[len];
		len++;
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

static char *zero_handler(char *str, int padding, int precision)
{
	int len;

	len = ft_strlen(str);

	 if ( precision > 0)
		return (width_handler(str, padding));
	else if (str[0] == '-')
		return (neg_pad_handler(str, padding, len));
	else
		return (pos_pad_handler(str, padding, len));
}


void	u_integer_handler(char **format, va_list var, int *pft_ret)
{
	int len;
	char *str;
	t_flag_attribs *flag;

	flag = integer_parser(format, var);
	str = ft_uitoa(va_arg(var, unsigned int));
	if (flag->precision > 0 || flag->prec_is_dot == 1)
		str = precision_handler(str, flag->precision, flag->prec_is_dot);
	if (flag->width != 0)
		str = width_handler(str, flag->width);
	if (flag->padding > 0)
		str = zero_handler(str, flag->padding, flag->precision);
	while (**format != 'u')
		(*format)++;
	(*format)++;
	len = ft_strlen(str);
	write(1, str, len);
	*pft_ret = *pft_ret + len;
	free(flag);
	free(str);
}
