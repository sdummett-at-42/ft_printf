/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 10:00:40 by sdummett          #+#    #+#             */
/*   Updated: 2021/06/30 22:35:18 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	char *str = "String";
	ft_printf("%4.42d", 420);
	printf("||\n%4.42d", 420);
}

/*
int	main()
{
	char c 		= 'O';
	char str[]	= "YIIIKES";
	int	nb		= 2194812;
	unsigned int unb= -42;
	//long int hex = 42;


	printf("[ FT_PRINTF ]\n\n");
	ft_printf("Ceci est le %%c : ||%c||\nCeci est le %%s : ||%s||\nCeci est le %%p : ||%p||\nCeci est le %%d : ||%d||\nCeci est le %%i : ||%i||\nCeci est le %%u : ||%u||\nCeci est le %%x : ||%x||\nCeci est le %%X : ||%X||\n", c, str, &c,  nb, nb, unb, nb, nb);


	printf("\n[  PRINTF  ]\n\n");
	printf("Ceci est le %%c : ||%c||\nCeci est le %%s : ||%s||\nCeci est le %%p : ||%p||\nCeci est le %%d : ||%d||\nCeci est le %%i : ||%i||\nCeci est le %%u : ||%u||\nCeci est le %%x : ||%x||\nCeci est le %%X : ||%X||\n", c, str, &c,  nb, nb, unb, nb, nb);
		//	ft_printf("Hello %% World! %c", c);
	return 0;
}
*/


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
