/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:26:22 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/06 14:06:40 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.c"

void count_and_display(char **format, char *str, char c, int *ptf_ret)
{
	int len;
	
	if (c == 'd')
	{
		while (**format != c && **format != 'i')
			(*format)++;
	}
	else
	{
		while (**format != c)
			(*format)++;
	}
	(*format)++;
	len = ft_strlen(str);
	*ptf_ret = *ptf_ret + len;
	write(1, str, len);
}
