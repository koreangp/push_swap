/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:09:56 by pscala            #+#    #+#             */
/*   Updated: 2024/02/19 18:38:48 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap/push_swap.h"

void	other_actions(t_node **a, t_node **b, char *str)
{
	if (ft_strncmp(str, "rr\n", 3) == 0)
	{
		rotate(b);
		rotate(a);
	}
	else if (ft_strncmp(str, "ss\n", 3) == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else
	{
		ft_putendl_fd("Error", 2);
		free(str);
		stack_free(a);
		stack_free(b);
		exit(1);
	}
}

void	actions(t_node **a, t_node **b, char *str)
{
	if (ft_strncmp(str, "rra\n", 4) == 0)
		rev_rotate(a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rev_rotate(b);
	else if (ft_strncmp(str, "rr\n", 4) == 0)
	{
		rotate(b);
		rotate(a);
	}
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		swap(b);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		push(a, b);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rotate(b);
	else
		other_actions(a, b, str);
}

void	get_actions(t_node **a, t_node **b)
{
	char	*str;

	str = NULL;
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		actions(a, b, str);
		free(str);
	}
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		s;

	a = NULL;
	b = NULL;
	s = 1;
	if (ac == 1 || (ac == 2 && (!av[1][0])))
		return (0);
	else if (ac == 2)
		av = ft_split(av[s--], ' ');
	init_a(&a, av + s, s);
	get_actions(&a, &b);
	if ((is_sorted(a) == 1) && (list_count(b) == 0))
	{
		ft_putendl_fd("OK", 1);
		good();
	}
	else
	{
		ft_putendl_fd("KO", 1);
		bad();
	}
	stack_free(&a);
	stack_free(&b);
}
