/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 00:50:20 by kait-baa          #+#    #+#             */
/*   Updated: 2023/11/12 03:07:46 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(char *str, int chr)
{
	char	*last;

	last = NULL;
	while (*str != '\0')
	{
		if (*str == (char)chr)
			last = str;
		str++;
	}
	if (*str == (char)chr)
		return (str);
	return (last);
}
