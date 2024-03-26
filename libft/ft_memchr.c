/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 04:08:17 by kait-baa          #+#    #+#             */
/*   Updated: 2023/11/12 15:44:53 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		if (ptr[i] == (unsigned char )c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
 	char *src = "/|\x12\xff\x09\0\x42\042\0\42|\\";
	char *ptr = memchr(src, '\0', 12);
	char *ptr2 = ft_memchr(src, '\0', 12);
	printf("%p\n", ptr);
	printf("%p", ptr2);
	 	if (memchr(src, '\0', 12) == ft_memchr(src, '\0', 12))
			printf("ok");
		else
		printf("ko");
}*/
