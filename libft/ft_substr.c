/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:59:35 by pscala            #+#    #+#             */
/*   Updated: 2023/11/20 12:44:59 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*newstr;
	size_t			size;
	int				i;
	unsigned int	j;

	size = 0;
	i = 0;
	j = 0;
	while (s[j] && (j != start))
		j++;
	if (j < ft_strlen(s))
	{
		size = ft_strlen(s) - j;
		if (size > len)
			size = len;
	}
	newstr = malloc((size + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s[j] && (len-- > 0))
		newstr[i++] = s[j++];
	newstr[i] = '\0';
	return (newstr);
}
