/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 10:00:40 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/02 08:58:58 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	int ft_ret;
	int ret;
	char *str = "Stone";
	//ft_printf("%X", 444);
	//printf("||\n%X||\n", 444);
	ft_ret = ft_printf("Yay%c%s%prt%%e%d%i%uall%%ooo%x%XWAW\n", 'S', str, &str, 42, -42, 5555, 1000, 444);
	ret =       printf("Yay%c%s%prt%%e%d%i%uall%%ooo%x%XWAW\n", 'S', str, &str, 42, -42, 5555, 1000, 444);
//	printf("\nft_printf : %d | printf : %d\n", ft_ret, ret);
     //printf("Yay%c%s%prt%%e%d%i%uall%%ooo%x%XWAW\n", 'S', str, &str, 42, -42, 5555, 1000, 444);
//printf("ft_ret : %d | ret : %d\n", ft_ret, ret);
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
