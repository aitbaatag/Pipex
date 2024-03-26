/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 04:37:43 by kait-baa          #+#    #+#             */
/*   Updated: 2023/11/14 00:31:09 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destt;
	char		*srcc;
	size_t		i;

	destt = (char *)dest;
	srcc = (char *)src;
	i = 0;
	if (!dest && !src)
		return (0);
	while (n > i)
	{
		destt[i] = srcc[i];
		i++;
	}
	return (dest);
}
