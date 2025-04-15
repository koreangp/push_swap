/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:46:53 by pscala            #+#    #+#             */
/*   Updated: 2024/01/26 18:29:18 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_count(t_node *a)
{
	int	c;

	c = 0;
	while (a)
	{
		c++;
		a = a->next;
	}
	return (c);
}

int	get_pos(t_node **a, int num)
{
	int		pos;
	t_node	*current;

	current = *a;
	pos = 1;
	while (current->nbr != num)
	{
		pos++;
		current = current->next;
	}
	return (pos);
}
