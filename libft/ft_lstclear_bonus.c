/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-baa <kait-baa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 03:13:22 by kait-baa          #+#    #+#             */
/*   Updated: 2023/11/14 03:03:19 by kait-baa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*next2;

	ptr = *lst;
	if (!*lst || !del || !lst)
		return ;
	while (ptr != NULL)
	{
		(del)(ptr->content);
		next2 = ptr->next;
		free(ptr);
		ptr = next2;
	}
	*lst = NULL;
}
