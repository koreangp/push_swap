/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:51:55 by pscala            #+#    #+#             */
/*   Updated: 2024/02/13 19:36:15 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **a, t_node **b)
{
	if (list_count(*a) == 3)
		sort3(a);
	else
		new_algo(a, b);
}

void	sort3(t_node **a)
{
	if (((*a)->nbr > (*a)->next->nbr) && ((*a)->nbr > (*a)->next->next->nbr))
	{
		ra(a);
	}
	else if (((*a)->next->next->nbr > (*a)->next->nbr)
		&& ((*a)->next->next->nbr > (*a)->nbr))
		sa(a);
	else
		rra(a);
	if (!is_sorted(*a))
		sa(a);
}

int	is_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}
