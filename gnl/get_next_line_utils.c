/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:13:45 by pscala            #+#    #+#             */
/*   Updated: 2023/12/06 16:22:02 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	if (!s)
		return (NULL);
	i = 0;
	uc = (unsigned char)c;
	while (s[i] || c == 0)
	{
		if ((unsigned char)s[i] == uc)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}
