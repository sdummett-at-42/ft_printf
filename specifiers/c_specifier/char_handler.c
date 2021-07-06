/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 02:13:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/06 23:40:53 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static char	*char_width_handler(char *str, int width)
{
	int		i;
	int		len;

	len = ft_strlen(str);
	i = 0;
	if (width > 0)
		width = width - 1;
	else
		width = width + 1;
	if (width < 0)
	{
		width = (width * -1) - len;
		if (width > 0)
			str = width_handler(str, width);
	}
	else if (width > 0)
	{
		width = width - len;
		if (width > 0)
			str = width_handler(str, width);
	}
	return (str);
}
static int count_skip_display(char **format, t_flag_attribs *flag, char *str, char c)
{
	int		len;
	len = ft_strlen(str);

	while (**format != 'c')
		(*format)++;
	if (flag->width > 0)
		write(1, str, len);
	write(1, &c, 1);
	if (flag->width < 0)
		write(1, str, len);
	(*format)++;
	return (len);
}

void	char_handler(char **format, va_list var, int *ptf_ret)
{
	t_flag_attribs	*flag;
	char			*str;
	char			c;
	int				len;

	len = 0;
	flag = format_parser(format, var);
	c = va_arg(var, unsigned int);
	str = ft_strdup("");
	if (str == NULL)
		return ;
	if (flag->precision > 0)
		str = padding_handler(str, flag->padding, flag->precision, \
				flag->prec_is_dot);
	else if (flag->padding > 0 && flag->precision != 0)
		flag->width = flag->padding;
	if (flag->width != 0)
		str = char_width_handler(str, flag->width);
	len = count_skip_display(format, flag, str, c);
	*ptf_ret = *ptf_ret + len + 1;
	free(str);
	free(flag);
}
