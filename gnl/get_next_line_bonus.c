/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:09:39 by pscala            #+#    #+#             */
/*   Updated: 2023/12/19 17:01:30 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*new;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		i++;
	new = (char *)malloc(i + 1);
	i = 0;
	if (new == NULL)
		return (NULL);
	while (s[i] != '\n' && s[i])
	{
		new[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strdupfree(char *storage, char *buffer)
{
	int		i;
	int		j;
	char	*new;

	if (!storage)
		return (ft_strdup(buffer));
	new = (char *)malloc(ft_strlen(storage) + ft_strlen(buffer) + 1);
	i = 0;
	if (new == NULL)
		return (NULL);
	while (storage[i])
	{
		new[i] = storage[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		new[i++] = buffer[j++];
	new[i] = '\0';
	free(storage);
	return (new);
}

void	ft_new_copy(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\n')
		i++;
	i++;
	while (s[i])
	{
		s[j] = s[i];
		i++;
		j++;
	}
	s[j] = '\0';
}

char	*ft_next_line(char *s, ssize_t byte)
{
	char	*line;

	line = ft_strdup(s);
	if (!line)
		return (NULL);
	free(s);
	if (byte == 0 && ft_strlen(line) < 1)
	{
		free(line);
		return (0);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	ssize_t		readbyte;
	char		*storage;

	storage = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbyte = 1;
	if (ft_strchr(buffer[fd], '\n') != 0)
	{
		storage = ft_strdup(ft_strchr(buffer[fd], '\n') + 1);
		ft_new_copy(buffer[fd]);
	}
	while (readbyte > 0 && ft_strchr(storage, '\n') == 0)
	{
		readbyte = read(fd, buffer[fd], BUFFER_SIZE);
		if (readbyte == -1)
			return (NULL);
		buffer[fd][readbyte] = '\0';
		storage = ft_strdupfree(storage, buffer[fd]);
	}
	return (ft_next_line(storage, readbyte));
}
// int	main(void)
// {
// 	int		fd;
// 	char	*str;
// 	char	*st;

// 	fd = open("tripouille/files/big_line_with_nl", O_RDONLY);
// 	// printf("[%d]\n", fd);
// 	str = get_next_line(0);
// 	printf("/%s", str);
// 	free(str);
// 	close(fd);
// }
