/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:54:08 by pscala            #+#    #+#             */
/*   Updated: 2023/11/19 16:41:43 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	lens1;
	size_t	lennewstr;

	lens1 = ft_strlen(s1) + 1;
	newstr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	lennewstr = ft_strlen(s1) + ft_strlen(s2) + 1;
	ft_strlcpy(newstr, s1, lens1);
	ft_strlcat(newstr, s2, lennewstr);
	return (newstr);
}
