/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:51:32 by pscala            #+#    #+#             */
/*   Updated: 2023/11/17 16:22:07 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*tab;

	if (size != 0)
	{
		if (n > (SIZE_MAX / size))
			return (NULL);
	}
	tab = malloc(size * n);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, size * n);
	return (tab);
}
