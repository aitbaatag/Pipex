/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:13:33 by kait-baa          #+#    #+#             */
/*   Updated: 2023/11/08 03:46:42 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = s1;
	str2 = s2;
	i = 0;
	while (n > i)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}
/*int		main(int argc, const char *argv[])
{
		printf("%d",ft_memcmp("t\200", "t\0", 2));
		printf ("\n");
		printf("%d",ft_memcmp("abcdefghij", "abcdefgxyz", 7));
		printf ("\n");
		printf ("\n");
		printf("%d",memcmp("t\200", "t\0", 2));
		printf ("\n");
		printf("%d",memcmp("abcdefghij", "abcdefgxyz", 7));
}*/
