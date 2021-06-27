/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:04:56 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/27 18:28:45 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
 *	1 : %c
 *	2 : %s
 *	3 : %p
 *	4 : %d - %i
 *	5 : %u
 *	6 : %x - %X
 *	7 : %% 
*/ 

int	search_specifier(char **format)
{
	int i;
	int ret;

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
		else if ((*format)[i] == 'x' || (*format)[i] == 'X')
			ret = 6;
		else if ((*format)[i] == '%')
			ret = 7;
		else
			i++;
		if (ret != 0)
			break ;
	}
	if (ret != 0)
		(*format)++;
	return (ret);
}

/*
 *	Main test for this function
 *	OK !
*/	

/*
int main()
{
	int i;
	char *format = "%c %s %p %d %i %u %x %X %%";

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
*/
