/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 02:35:57 by kait-baa          #+#    #+#             */
/*   Updated: 2023/11/13 00:20:16 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;
	size_t	n;

	if ((!dest || !src) && !size)
		return (0);
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	n = 0;
	i = len_dest;
	if (len_dest >= size)
		return (len_src + size);
	while (src[n] != '\0' && n < size - i - 1)
	{
		dest[i + n] = src[n];
		n++;
	}
	dest[i + n] = '\0';
	return (len_dest + len_src);
}
