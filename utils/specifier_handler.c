/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 23:10:31 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/02 19:11:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	call_handler(int handler_choice, char **format, va_list var, int *len)
{
	if (handler_choice == 1)
		char_handler(format, var, len);
	else if (handler_choice == 2)
		str_handler(format, var, len);
	else if (handler_choice == 3)
		pointer_handler(format, var, len);
	else if (handler_choice == 4)
		integer_handler(format, var, len);
	else if (handler_choice == 5)
		u_integer_handler(format, var, len);
	else if (handler_choice == 6)
		hexalow_handler(format, var, len);
	else if (handler_choice == 7)
		hexaup_handler(format, var, len);
	else if (handler_choice == 8)
		percent_handler(format, var, len);
}

/*
 *	1 : %c
 *	2 : %s
 *	3 : %p
 *	4 : %d - %i
 *	5 : %u
 *	6 : %x
 *	7 : %X
 *	8 : %%
*/

int	search_specifier(char **format)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while ((*format)[i] != '\0')
	{
		if ((*format)[i] == 'c')
			ret = 1;
		else if ((*format)[i] == 's')
			ret = 2;
		else if ((*format)[i] == 'p')
			ret = 3;
		else if ((*format)[i] == 'd' || (*format)[i] == 'i')
			ret = 4;
		else if ((*format)[i] == 'u')
			ret = 5;
		else if ((*format)[i] == 'x')
			ret = 6;
		else if ((*format)[i] == 'X')
			ret = 7;
		else if ((*format)[i] == '%')
			ret = 8;
		else
			i++;
		if (ret != 0)
			break ;
	}
	return (ret);
}

/*
 *	Main test for this function (search_specifier)
 *	OK !
*/

/*
int main()
{
	int i;
	char *format = "%vfc    %vvs %    p % f f  d %    i % u %nnx %       l  X %l%";

	i = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			printf("specifier = %d\n", search_specifier(&format));
		}
		else
			format++;
	}
	return (0);
}
E
*/
