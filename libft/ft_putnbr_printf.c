/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:03:07 by pscala            #+#    #+#             */
/*   Updated: 2024/01/12 15:44:43 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_printf(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putnbr_printf(n / 10, count);
		ft_putnbr_printf(-(n % 10), count);
	}
	else if (n < 0)
	{
		ft_putchar_printf('-', count);
		ft_putnbr_printf(-n, count);
	}
	else if (n > 9)
	{
		ft_putnbr_printf(n / 10, count);
		ft_putnbr_printf(n % 10, count);
	}
	else
		ft_putchar_printf(n + '0', count);
}
