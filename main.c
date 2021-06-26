/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 10:00:40 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/26 19:01:19 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	//char c = 'S';

	ft_printf("Hello Wor%%ld!");
	return 0;
}

/*
int main()
{
	void *lol;
	char str[] = "Le Basket !";
	int nb		= -210;
	unsigned int unb = 450;
	char c = 'l';
	int	inhex = 900;

	ft_putchar(c);
	printf("||%c||\n", c);
	ft_putstr(str);
	printf("||%s||\n", str);
	ft_putaddr(lol);
	printf("||%p||\n", lol);
	ft_putnbr(nb);
	printf("||%d||\n", nb);
	ft_putnbr(nb);
	printf("||%i||\n", nb);
	ft_putnbr(unb);
	printf("||%u||\n", unb);
	ft_puthex_low(nb);
	printf("||%x||\n", nb);
	ft_puthex_up(nb);
	printf("||%X||\n", nb);

	return (0);
}
*/
