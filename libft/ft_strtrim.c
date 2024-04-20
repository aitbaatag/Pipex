/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 03:25:58 by kait-baa          #+#    #+#             */
/*   Updated: 2023/11/12 05:41:09 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len_s1;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	len_s1 = ft_strlen(s1);
	while (start < len_s1 && ft_strchr(set, s1[start]) != NULL)
		start++;
	if (start >= len_s1)
		return (ft_strdup(""));
	while (len_s1 > 0 && ft_strchr(set, s1[len_s1 - 1]) != NULL)
	{
		len_s1--;
	}
	return (ft_substr(s1, start, len_s1 - start));
}
