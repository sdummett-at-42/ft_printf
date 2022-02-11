/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:29:53 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/28 19:33:36 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_charset(unsigned char ch, char const *set)
{
	while (*set)
	{
		if (ch == *set)
			return (42);
		set++;
	}
	return (0);
}

static size_t	len_of_str(char const *s1, char const *set)
{
	int	len;

	while (check_charset(*s1, set) && *s1)
		s1++;
	if (*s1 == 0)
		return (0);
	len = 0;
	while (*(s1 + len))
		len++;
	while (check_charset(*(s1 + len - 1), set) && len)
		len--;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	len;

	if (!s1)
		return (0);
	len = len_of_str(s1, set);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	*(str + len) = 0;
	while (check_charset(*s1, set) && *s1)
		s1++;
	if (*s1 == 0)
		return (str);
	while (len)
	{
		len--;
		*(str + len) = *(s1 + len);
	}
	return (str);
}
