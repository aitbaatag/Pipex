/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 03:25:39 by kait-baa          #+#    #+#             */
/*   Updated: 2023/11/14 02:08:54 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	b;

	i = 0;
	if (!s1 && !n)
		return (NULL);
	if (!*s2)
		return ((char *)s1);
	while (s1[i] && n > i)
	{
		b = 0;
		while (s1[i + b] == s2[b] && n > i + b)
		{
			b++;
			if (s2[b] == '\0')
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
