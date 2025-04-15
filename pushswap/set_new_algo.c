/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:44:42 by pscala            #+#    #+#             */
/*   Updated: 2024/02/14 18:01:52 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_pos(t_node *a, t_node *b)
{
	int	i;

	i = 0;
	while (a)
	{
		a->pos = i;
		i++;
		a = a->next;
	}
	i = 0;
	while (b)
	{
		b->pos = i;
		i++;
		b = b->next;
	}
}

void	assign_target(t_node *a, t_node *b)
{
	int		target;
	t_node	*current;

	while (b)
	{
		target = biggest(a) + 1;
		current = a;
		while (current)
		{
			if (current->nbr > b->nbr && current->nbr < target)
			{
				target = current->nbr;
				b->target_n = target;
				b->target_pos = current->pos;
			}
			current = current->next;
		}
		if (target == biggest(a) + 1)
		{
			b->target_n = smallest(a);
			b->target_pos = smallest_pos(a);
		}
		b = b->next;
	}
}

int	new_calc_price(t_node **a, t_node **b, t_node *current)
{
	return (lower(communist(a, b, current), capitalist(a, b, current)));
}

int	calc_cheapest(t_node **a, t_node **b)
{
	int		cheapest;
	int		cheapest_nbr;
	t_node	*current;

	cheapest = INT_MAX;
	cheapest_nbr = (*b)->nbr;
	current = *b;
	while (current)
	{
		if (cheapest > new_calc_price(a, b, current))
		{
			cheapest = new_calc_price(a, b, current);
			cheapest_nbr = current->nbr;
		}
		current = current->next;
	}
	return (cheapest_nbr);
}

void	new_algo(t_node **a, t_node **b)
{
	int	cheapest;
	int	moyenne;

	moyenne = calc_moyenne(*a);
	while (list_count(*a) > 3 && !is_sorted(*a))
	{
		pb(b, a);
		if ((*b)->nbr > moyenne)
			rb(b);
	}
	if (!is_sorted(*a))
		sort3(a);
	while (list_count(*b) > 0)
	{
		init_pos(*a, *b);
		assign_target(*a, *b);
		cheapest = calc_cheapest(a, b);
		push_cheapest(a, b, cheapest);
	}
	if (!is_sorted(*a) && smallest_pos(*a) < (list_count(*a) / 2))
		ra_loop(a);
	else if (!is_sorted(*a))
		rra_loop(a);
}
