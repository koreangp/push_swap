/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:26:42 by pscala            #+#    #+#             */
/*   Updated: 2024/01/12 15:44:48 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hexa(unsigned int n, int *count, char *base)
{
	if (n > 15)
	{
		ft_putnbr_hexa(n / 16, count, base);
		ft_putnbr_hexa(n % 16, count, base);
	}
	else
		ft_putchar_printf(base[n], count);
}
