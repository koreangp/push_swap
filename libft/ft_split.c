/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:55:02 by pscala            #+#    #+#             */
/*   Updated: 2023/11/25 15:55:57 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countw(char const *s, char c)
{
	int	count;
	int	flag;
	int	i;

	count = 0;
	flag = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int	lenw(char const *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start] && s[start] != c)
	{
		start++;
		i++;
	}
	return (i);
}

static char	**ft_free(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
	return (NULL);
}

static char	**word(char const *s, char c, char **split)
{
	int	start;
	int	i;
	int	j;

	start = 0;
	i = 0;
	while (s[start])
	{
		j = 0;
		if (s[start] != c)
		{
			split[i] = malloc((lenw(s, c, start) + 1) * sizeof(char));
			if (!split[i])
				return (ft_free(split, i));
			while (s[start] != c && s[start])
				split[i][j++] = s[start++];
			split[i++][j] = '\0';
		}
		else
			start++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;

	if (!s)
		return (NULL);
	words = countw(s, c);
	split = malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (word(s, c, split));
}

// int	main(void)
// {
// 	char *str = "bonjour jojo jojolion jojoland";
// 	char c = ' ';
// 	char **result;
// 	result = ft_split(str, c);
// 	int i = 0;
// 	if (result == 0)
// 		printf("free ;D");
// 	else
// 	{
// 		while (result[i])
// 		{
// 			printf("%s\n", result[i]);
// 			i++;
// 		}
// 	}
// 	ft_free(result, i);
// }