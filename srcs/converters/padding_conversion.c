/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:44:37 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/08 22:29:26 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	insert_padding(char *new, int padding, int i)
{
	while (padding != 0)
	{
		new[i] = '0';
		i++;
		padding--;
	}
	return (i);
}

static void	copy_str(char *new, char *str, int i, int j)
{
	while (str[j] != '\0')
	{
		new[i] = str[j];
		i++;
		j++;
	}
	new[i] = '\0';
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
	i = insert_padding(new, padding, 0);
	copy_str(new, str, i, 0);
	free(str);
	return (new);
}

static char	*neg_pos_pad_handler(char *str, int padding, int len)
{
	int		i;
	char	*new;

	if (padding <= len)
		return (str);
	new = malloc(sizeof(char) * padding + 1);
	if (new == NULL)
		return (NULL);
	if (*str == '-')
		new[0] = '-';
	else if (*str == '+')
		new[0] = '+';
	else if (*str == ' ')
		new[0] = ' ';
	padding = padding - len;
	i = insert_padding(new, padding, 1);
	copy_str(new, str, i, 1);
	free(str);
	return (new);
}

char	*padding_conversion(char *str, int padding, int precision, int dot)
{
	int	len;

	len = ft_strlen(str);
	if (precision > 0 || dot == 1)
		return (width_conversion(str, padding));
	else if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
		return (neg_pos_pad_handler(str, padding, len)); //func special flag 
	else if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		return (x_prefix_pad_conversion(str, padding, len));
	else
		return (pos_pad_handler(str, padding, len));
}
