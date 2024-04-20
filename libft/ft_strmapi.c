/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 03:25:06 by kait-baa          #+#    #+#             */
/*   Updated: 2023/11/13 16:35:45 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				len_s;
	unsigned int	i;
	char			*new_string;

	if (!s || !f)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	new_string = malloc((len_s + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	new_string[len_s] = '\0';
	while (s[i])
	{
		new_string[i] = (f)(i, s[i]);
		i++;
	}
	return (new_string);
}
