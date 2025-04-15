/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_regime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:20:35 by pscala            #+#    #+#             */
/*   Updated: 2024/02/14 17:42:54 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	capitalist(t_node **a, t_node **b, t_node *current)
{
	int	price_current;
	int	price_target;
	int	capital_price;

	price_current = lower((current->pos), (list_count(*b) - (current->pos)));
	price_target = lower((current->target_pos), (list_count(*a)
				- (current->target_pos)));
	capital_price = price_current + price_target;
	return (capital_price);
}

int	communist(t_node **a, t_node **b, t_node *current)
{
	int	biggest_pos;
	int	smallest_pos;
	int	soviet_price;

	biggest_pos = higher(current->pos, current->target_pos);
	smallest_pos = higher((list_count(*b) - (current->pos)), (list_count(*a)
				- (current->target_pos)));
	soviet_price = lower(biggest_pos, smallest_pos);
	return (soviet_price);
}
