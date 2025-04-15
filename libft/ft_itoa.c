/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:40:51 by pscala            #+#    #+#             */
/*   Updated: 2023/11/22 15:01:56 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	if (n == 0)
		return (++count);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*newstr(char *str, long n, int count)
{
	int	sign;
	int	i;

	sign = 0;
	i = count;
	if (n < 0)
	{
		str[0] = '-';
		sign++;
		n = -n;
	}
	while (i > sign)
	{
		str[--i] = n % 10 + '0';
		n = n / 10;
	}
	str[count] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nbr;
	long	ln;

	ln = n;
	nbr = count(ln);
	str = malloc((nbr + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (newstr(str, ln, nbr));
}
