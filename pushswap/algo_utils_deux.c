/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_deux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:29:03 by pscala            #+#    #+#             */
/*   Updated: 2024/02/14 18:04:29 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_loop(t_node **a)
{
	while (smallest(*a) != (*a)->nbr)
		ra(a);
}

void	rra_loop(t_node **a)
{
	while (smallest(*a) != (*a)->nbr)
		rra(a);
}

int	calc_moyenne(t_node *a)
{
	t_node	*current;
	int		nbr;
	int		i;

	current = a;
	i = 0;
	nbr = 0;
	while (current)
	{
		nbr = nbr + current->nbr;
		i++;
		current = current->next;
	}
	return (nbr / i);
}
