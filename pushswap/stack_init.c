/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:41:52 by pscala            #+#    #+#             */
/*   Updated: 2024/11/22 19:16:05 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int_max(char *str)
{
	int	j;
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	j = ft_strlen(&str[i]);
	if (j == 10)
	{
		if (str[0] == '-')
			return (ft_strncmp(str + i, "2147483648", j));
		else if (str[0] == '+')
			return (ft_strncmp(str + i, "2147483647", j));
	}
	else if (j > 10)
		return (1);
	return (0);
}

t_node	*new_node_init(int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->nbr = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	add_back(t_node **stack, t_node *new_node)
{
	t_node	*last_node;

	if (!(*stack))
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		*stack = new_node;
		return ;
	}
	last_node = get_last_node(*stack);
	last_node->next = new_node;
	new_node->prev = last_node;
	new_node->next = NULL;
}

void	add_front(t_node **stack, t_node *new_node)
{
	if (!(*stack))
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
		new_node->prev = NULL;
		*stack = new_node;
	}
}

void	init_a(t_node **a, char **av, int s)
{
	int	i;

	i = 0;
	if (!av[i])
		error(a, av, s);
	while (av[i])
	{
		if (is_num(av[i]) == 0)
			error(a, av, s);
		if (is_int_max(av[i]) > 0)
			error(a, av, s);
		if (doublons(*a, ft_atoi(av[i])) == -1)
			error(a, av, s);
		add_back(a, new_node_init(ft_atoi(av[i])));
		i++;
	}
	if (s == 0)
		free_split(av, s);
}
