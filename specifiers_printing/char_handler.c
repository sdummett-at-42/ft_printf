/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 02:13:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/28 05:39:17 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
 *	Flags 
 *	1 : 0
 *	2 : .
 *	3 : -
*/ 

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*zero_flag(char **format, va_list var)
{
	int	nb;
	char *str;

	nb = 0;
	if ((*format)[1] <= '9' && (*format)[1] >= '0')
	{
		printf("[%c]\n", **format);
		nb = nb + ft_atoi(*format) - 1;
		printf("nbbb = %d\n", nb);
	}
	else if ((*format)[1] == '*')
	{
		nb = va_arg(var, int) - 1;
		printf("nb => %d\n", nb);
	}
	if (nb < 1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * nb + 1);
	str[nb] = '\0';
	printf("nb = %d\n", nb);
	while (nb != 0)
	{
		nb--;
		str[nb] = '0';
	}
	return (str);
}

void	char_handler(char **format, va_list var)
{
	char *str;
	
	//(*format)++;
	while (**format != '\0')
	{
		if (**format == '0')
		{
			str = zero_flag(format, var);
			if (str != NULL)
				ft_putstr(str);
			ft_putchar(va_arg(var, int));
			while (**format != 'c')
				(*format)++;
			(*format)++;
			return ; /////
		}
	}
}

