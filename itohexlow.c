/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itohexlow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:41:39 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/21 20:24:34 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char*	itohexlow(long int value)
{
	int	len;
	int value_tmp;
	char	*ptr;
	char	*hexbase;

	hexbase = "0123456789abcdef";
	len = 0;
	value_tmp = value;
	while (value_tmp)
	{
		value_tmp = value_tmp / 16;
		len++;
	}
//	printf("i = %d\n", len);
	ptr = (char *)malloc(sizeof(char) * len + 1);
//	if (value == 0)
//	{
//		ptr[]
//	}
	ptr[len] = 0;
	while (value)
	{
		ptr[len - 1] = *(hexbase + value % 16);
		value = value / 16;
		len--;
	}
	return (ptr);
}	

int main()
{
	char *ptr;
	int nb = 1;
	//ptr = 
	printf("||%s||\n", itohexlow(nb));
	printf(">|%x|<\n", nb);
	//printf("||%s||", ptr);
	return (0);
}
