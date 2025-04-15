/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_adress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:18:48 by pscala            #+#    #+#             */
/*   Updated: 2024/01/12 15:44:53 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_adress(size_t p, int *count, char *base, int start)
{
	if (p == 0 && !start)
		return (ft_putstr_printf("(nil)", count));
	else if (!start)
		ft_putstr_printf("0x", count);
	if (p > 15)
	{
		ft_putnbr_adress(p / 16, count, base, 1);
		ft_putnbr_adress(p % 16, count, base, 1);
	}
	else
		ft_putchar_printf(base[p], count);
}
