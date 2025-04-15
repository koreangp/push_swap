/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:43:28 by pscala            #+#    #+#             */
/*   Updated: 2023/11/20 12:51:21 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (j > i && ft_strchr(set, s1[j]) != NULL)
		j--;
	newstr = ft_substr(s1, i, j - i + 1);
	if (!newstr)
		return (NULL);
	return (newstr);
}

// int	main(void)
// {
// 	char const *str = "    bo jour    ";
// 	char const *set = " ";
// 	printf("%s\n", ft_strtrim(str, set));
// }