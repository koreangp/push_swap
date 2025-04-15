/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:07:03 by pscala            #+#    #+#             */
/*   Updated: 2023/11/27 14:42:39 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last;
	t_list	*temp;

	last = *lst;
	while (last)
	{
		temp = last->next;
		del(last->content);
		free(last);
		last = temp;
	}
	*lst = NULL;
}
