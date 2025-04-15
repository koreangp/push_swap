/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:50:20 by pscala            #+#    #+#             */
/*   Updated: 2024/11/22 19:01:33 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && (*s1 || *s2))
	{
		if (*(unsigned char *)s1 > *(unsigned char *)s2)
			return (1);
		else if (*(unsigned char *)s1 < *(unsigned char *)s2)
			return (-1);
		n--;
		s1++;
		s2++;
	}
	return (0);
}

// int	main(void)
// {
// 	char *s1 = "A";
// 	char *s2 = "a";
// 	size_t size = 3;

// 	printf("ma fonction %d\n", ft_strncmp(s1, s2, size));
// 	printf("vrai fonction %d\n", ft_strncmp(s1, s2, size));
// }