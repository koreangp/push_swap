/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:58:54 by pscala            #+#    #+#             */
/*   Updated: 2024/01/26 20:23:02 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **dest, t_node **src)
{
	t_node	*temp;

	if (*src != NULL)
	{
		temp = *src;
		if (temp->next)
		{
			temp->next->prev = NULL;
			*src = temp->next;
		}
		else
			*src = NULL;
		add_front(dest, temp);
	}
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
	ft_printf("pb\n");
}
