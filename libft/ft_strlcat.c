/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:18:42 by pscala            #+#    #+#             */
/*   Updated: 2023/11/15 15:02:52 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	len_s;
	size_t	len_d;

	j = 0;
	len_s = ft_strlen(src);
	len_d = ft_strlen(dest);
	if (size <= len_d)
		return (len_s + size);
	while (src[j] && len_d + j < size - 1)
	{
		dest[len_d + j] = src[j];
		j++;
	}
	dest[len_d + j] = '\0';
	return (len_s + len_d);
}
