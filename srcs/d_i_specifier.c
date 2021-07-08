/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 02:24:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/08 18:35:09 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*pos_prefix_handler(char *str)
{
	int		i;
	int		len;
	char	*new;

	if (*str == '-')
		return (str);
	len = ft_strlen(str) + 1;
	new = (char *)malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	new[0] = '+';
	i = 1;
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

static char	*blank_handler(char *str)
{
	int		i;
	int		len;
	char	*new;

	if (*str == '-')
		return (str);
	len = ft_strlen(str) + 1;
	new = (char *)malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	new[0] = ' ';
	i = 1;
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

void	d_i_printer(char **fmt, va_list var, int *ptf_ret)
{
	char		*str;
	t_attribs	*flag;

	flag = fmt_parser(fmt, var);
	if (flag->prec_is_dot == 0 && flag->padding < 0)
		flag->width = flag->padding;
	str = ft_itoa(va_arg(var, int));
	str = check_if_eq_zero(str, flag->prec_is_dot);
	if (flag->precision > 0)
		str = precision_handler(str, flag->precision);
	if (flag->blank == 1)
		str = blank_handler(str);
	if (flag->pos_prefix == 1)
		str = pos_prefix_handler(str);
	if (flag->width != 0)
		str = width_handler(str, flag->width);
	if (flag->padding > 0 || flag->prec_is_dot == 1)
		str = padding_handler(str, flag->padding, \
				flag->precision, flag->prec_is_dot);
	count_and_display(fmt, str, 'd', ptf_ret);
	free(flag);
	free(str);
}
