/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:22:59 by pscala            #+#    #+#             */
/*   Updated: 2024/02/14 17:42:55 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_capital(t_node **a, t_node **b, t_node *current)
{
	int	nbr_b;
	int	nbr_a;

	nbr_b = current->nbr;
	nbr_a = current->target_n;
	if (current->pos < (list_count(*b) - current->pos))
	{
		while ((*b)->nbr != nbr_b)
			rb(b);
		while ((*a)->nbr != nbr_a)
			rra(a);
	}
	else
	{
		while ((*b)->nbr != nbr_b)
			rrb(b);
		while ((*a)->nbr != nbr_a)
			ra(a);
	}
	pa(a, b);
}

void	move_communist1(t_node **a, t_node **b, t_node *current)
{
	int	nbr_b;
	int	nbr_a;
	int	biggest_pos;

	biggest_pos = higher(current->pos, current->target_pos);
	nbr_b = current->nbr;
	nbr_a = current->target_n;
	if (biggest_pos == current->pos)
	{
		while ((*a)->nbr != nbr_a)
			rr(a, b);
		while ((*b)->nbr != nbr_b)
			rb(b);
	}
	else
	{
		while ((*b)->nbr != nbr_b)
			rr(a, b);
		while ((*a)->nbr != nbr_a)
			ra(a);
	}
}

void	move_communist2(t_node **a, t_node **b, t_node *current)
{
	int	nbr_b;
	int	nbr_a;
	int	smallest_pos;

	smallest_pos = higher((list_count(*b) - (current->pos)), (list_count(*a)
				- (current->target_pos)));
	nbr_b = current->nbr;
	nbr_a = current->target_n;
	if (smallest_pos == (list_count(*b) - (current->pos)))
	{
		while ((*a)->nbr != nbr_a)
			rrr(a, b);
		while ((*b)->nbr != nbr_b)
			rrb(b);
	}
	else
	{
		while ((*b)->nbr != nbr_b)
			rrr(a, b);
		while ((*a)->nbr != nbr_a)
			rra(a);
	}
}

void	move_communist(t_node **a, t_node **b, t_node *current)
{
	int	biggest_pos;
	int	smallest_pos;
	int	soviet_price;

	biggest_pos = higher(current->pos, current->target_pos);
	smallest_pos = higher((list_count(*b) - (current->pos)), (list_count(*a)
				- (current->target_pos)));
	soviet_price = lower(biggest_pos, smallest_pos);
	if (soviet_price == biggest_pos)
	{
		move_communist1(a, b, current);
	}
	else
	{
		move_communist2(a, b, current);
	}
	pa(a, b);
}

void	push_cheapest(t_node **a, t_node **b, int cheapest)
{
	t_node	*current;

	current = *b;
	while ((current->nbr) != (cheapest))
		current = current->next;
	if (capitalist(a, b, current) < communist(a, b, current))
		move_capital(a, b, current);
	else
		move_communist(a, b, current);
}
