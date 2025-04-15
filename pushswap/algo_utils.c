/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:03:51 by pscala            #+#    #+#             */
/*   Updated: 2024/02/14 17:42:54 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_pos(t_node *a)
{
	int	num;
	int	pos;

	num = INT_MAX;
	while (a)
	{
		if (num > (a)->nbr)
		{
			num = (a)->nbr;
			pos = a->pos;
		}
		(a) = (a)->next;
	}
	return (pos);
}

int	higher(int x, int y)
{
	if (y > x)
		return (y);
	return (x);
}

int	lower(int x, int y)
{
	if (y < x)
		return (y);
	return (x);
}

int	biggest(t_node *a)
{
	int	num;

	num = INT_MIN;
	while (a)
	{
		if (num < (a)->nbr)
			num = (a)->nbr;
		(a) = (a)->next;
	}
	return (num);
}

int	smallest(t_node *a)
{
	int	num;

	num = INT_MAX;
	while (a)
	{
		if (num > (a)->nbr)
			num = (a)->nbr;
		(a) = (a)->next;
	}
	return (num);
}
