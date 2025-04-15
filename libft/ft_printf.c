/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:34:41 by pscala            #+#    #+#             */
/*   Updated: 2024/01/12 15:47:37 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <unistd.h>

static void	ft_test_type(va_list args, char c, int *count)
{
	if (c == 'c')
		ft_putchar_printf(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr_printf(va_arg(args, char *), count);
	else if (c == '%')
		ft_putchar_printf('%', count);
	else if (c == 'p')
		ft_putnbr_adress((size_t)va_arg(args, void *), count,
			"0123456789abcdef", 0);
	else if (c == 'd' || c == 'i')
		ft_putnbr_printf(va_arg(args, int), count);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_putnbr_hexa(va_arg(args, unsigned int), count, "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_hexa(va_arg(args, unsigned int), count, "0123456789ABCDEF");
}

static void	ft_print(const char *format, va_list args, int *count)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && (ft_strchr("cspdiuxX%", format[i + 1]) != NULL))
		{
			ft_test_type(args, format[i + 1], count);
			i++;
		}
		else
			ft_putchar_printf(format[i], count);
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		nbofchar;
	va_list	args;

	if (format == NULL)
		return (-1);
	nbofchar = 0;
	va_start(args, format);
	ft_print(format, args, &nbofchar);
	va_end(args);
	return (nbofchar);
}

// #define TEST "%p\n", (void *)0

// #include "ft_printf.h"

// int	main(void)
// {
// 	int	i;
// 	int	j;

// 	i = ft_printf(TEST);
// 	j = printf(TEST);
// 	printf("i = %d\n j = %d\n", i, j);
// }