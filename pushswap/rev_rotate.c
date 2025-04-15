/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:31:26 by pscala            #+#    #+#             */
/*   Updated: 2024/02/15 15:42:25 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_node **stack)
{
	int		temp;
	t_node	*current;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		current = get_last_node(*stack);
		temp = current->nbr;
		while (current->prev)
		{
			current->nbr = current->prev->nbr;
			current = current->prev;
		}
		(*stack)->nbr = temp;
	}
}

void	rra(t_node **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_node **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
