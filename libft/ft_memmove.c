/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:11:10 by kait-baa          #+#    #+#             */
/*   Updated: 2023/11/11 22:26:06 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destt;
	char		*srcc;
	size_t		i;

	i = 0;
	if (!dest && !src)
		return (dest);
	if (dest == src)
		return (dest);
	srcc = (char *)src;
	destt = (char *)dest;
	if (dest > src)
	{
		while (n--)
			destt[n] = srcc[n];
	}
	else
	{
		i = -1;
		while (n > ++i)
		{
			destt[i] = srcc[i];
		}
	}
	return (dest);
}
