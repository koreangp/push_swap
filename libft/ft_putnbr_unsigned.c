/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:17:32 by pscala            #+#    #+#             */
/*   Updated: 2024/01/12 15:44:34 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10, count);
		ft_putnbr_unsigned(n % 10, count);
	}
	else
		ft_putchar_printf(n + '0', count);
}
