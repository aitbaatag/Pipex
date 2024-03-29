/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 03:24:45 by kait-baa          #+#    #+#             */
/*   Updated: 2024/03/21 20:50:21 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dst, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = dst;
	while (n > i)
	{
		*(ptr + i) = 0;
		i++;
	}
}
