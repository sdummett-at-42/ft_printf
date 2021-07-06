/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexalow_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 02:24:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/06 14:29:31 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static t_flag_attribs	*integer_parser(char **format, va_list var)
{
	int				i;
	int				neg;
	t_flag_attribs	*flag;

	flag = struct_init();
	i = 0;
	neg = 1;
	if ((*format)[i] == '0')
	{
		i++;
		if ((*format)[i] == '-')
			flag->padding = 0;
		else if ((*format)[i] == '*')
			flag->padding = va_arg(var, int);
		else
			flag->padding = ft_atoi(&(*format)[i]);
		while (((*format)[i] >= '0' && (*format)[i] <= '9') || \
				(*format)[i] == '*')
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
		while ((*format)[i] == '0')
			i++;
		if ((*format)[i] == '*')
		{
			flag->width = va_arg(var, int);
			if (neg == -1 && flag->width > 0)
				flag->width = flag->width * -1;
			i++;
		}
		else
			flag->width = ft_atoi(&(*format)[i]) * neg;
		while (((*format)[i] >= '0' && (*format)[i] <= '9') || \
				(*format)[i] == '-')
			i++;
	}
	if ((*format)[i] == '.')
	{
		i++;
		if ((*format)[i] == '*')
			flag->precision = va_arg(var, int);
		else if ((*format)[i] >= '0' && (*format)[i] <= '9')
			flag->precision = ft_atoi(&(*format)[i]);
		if (flag->precision == 0)
			flag->prec_is_dot = 1;
		while ((*format)[i] >= '0' && (*format)[i] <= '9')
			i++;
	}
	return (flag);
}

static char	*pos_prec_handler(char *str, int precision, int len)
{
	int		i;
	char	*new;

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

static char	*neg_prec_handler(char *str, int precision, int len)
{
	int		i;
	char	*new;

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

static char	*neg_wid_handler(char *str, int width, int len)
{
	int		i;
	char	*new;

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

static char	*pos_wid_handler(char *str, int width, int len)
{
	int		i;
	char	*new;

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
	new[i] = '\0';
	free(str);
	return (new);
}

static char	*precision_handler(char *str, int precision)
{
	int	len;

	len = ft_strlen(str);
	if (str[0] == '-')
		return (neg_prec_handler(str, precision, len));
	else
		return (pos_prec_handler(str, precision, len));
}

static char	*width_handler(char *str, int width)
{
	int	len;

	len = ft_strlen(str);
	if (width < 0)
		return (neg_wid_handler(str, width * -1, len));
	return (pos_wid_handler(str, width, len));
}

static char	*pos_pad_handler(char *str, int padding, int len)
{
	int		i;
	char	*new;

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

static char	*neg_pad_handler(char *str, int padding, int len)
{
	int		i;
	char	*new;

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

static char	*padding_handler(char *str, int padding, int precision, int dot)
{
	int	len;

	len = ft_strlen(str);
	 if (precision > 0 || dot == 1)
		return (width_handler(str, padding));
	else if (str[0] == '-')
		return (neg_pad_handler(str, padding, len));
	else
		return (pos_pad_handler(str, padding, len));
}

void	hexalow_handler(char **format, va_list var, int *ptf_ret)
{
	char			*str;
	t_flag_attribs	*flag;

	flag = integer_parser(format, var);
	if (flag->prec_is_dot == 0 && flag->padding < 0)
		flag->width = flag->padding;
	str = uitohex_low(va_arg(var, unsigned int));
	str = check_if_eq_zero(str, flag->prec_is_dot);
	if (flag->precision > 0)
		str = precision_handler(str, flag->precision);
	if (flag->width != 0)
		str = width_handler(str, flag->width);
	if (flag->padding > 0 || flag->prec_is_dot == 1)
		str = padding_handler(str, flag->padding, \
				flag->precision, flag->prec_is_dot);
	count_and_display(format, str, 'x', ptf_ret);
	free(flag);
	free(str);
}
