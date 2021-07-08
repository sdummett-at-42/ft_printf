/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp_flag_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:08:43 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/08 22:07:33 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*x_prefix_conversion(char *str, char spec)
{
	int		i;
	int		len;
	char	*new;

	len = ft_strlen(str) + 2;
	i = 0;
	while (str[i] == '0' && str[i] != '\0')
		i++;
	if (len - 2 == 0 || i == len - 2)
		return (str);
	new = malloc(sizeof(char) * len + 1);
	new[0] = '0';
	new[1] = spec;
	i = 2;
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
