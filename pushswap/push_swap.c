/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:12:52 by pscala            #+#    #+#             */
/*   Updated: 2024/02/15 15:09:19 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		s;

	a = NULL;
	b = NULL;
	s = 1;
	if (ac == 1)
		return (0);
	else if (ac == 2 && (!av[1][0]))
		return (ft_putendl_fd("Error", 2), 0);
	else if (ac == 2)
		av = ft_split(av[s--], ' ');
	init_a(&a, av + s, s);
	if (!is_sorted(a))
	{
		if (list_count(a) == 2)
			ra(&a);
		else
			sort(&a, &b);
	}
	stack_free(&a);
	return (0);
}
