/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:35:00 by pscala            #+#    #+#             */
/*   Updated: 2024/04/16 15:57:42 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **str, int s)
{
	int	i;

	if (s == 0)
	{
		i = 0;
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	stack_free(t_node **a)
{
	t_node	*temp;
	t_node	*current;

	if (*a)
	{
		current = *a;
		while (current)
		{
			temp = current->next;
			free(current);
			current = temp;
		}
		*a = NULL;
	}
}

void	error(t_node **a, char **str, int s)
{
	if (s == 0)
		free_split(str, s);
	stack_free(a);
	ft_putendl_fd("Error", 2);
	exit(1);
}
