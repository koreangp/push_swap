/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:20:38 by pscala            #+#    #+#             */
/*   Updated: 2023/11/15 16:00:11 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (s[i])
		i++;
	while (i >= 0 || c == 0)
	{
		if ((unsigned char)s[i] == uc)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char *s = "bonjour";
// 	printf("%s\n", ft_strrchr(s, 't'));
// 	printf("%s\n", strrchr(s, 't'));
// }