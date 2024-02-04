/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:37:24 by mlezcano          #+#    #+#             */
/*   Updated: 2023/10/29 20:21:36 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_traincontainer(int fd, char *container)
{
	char	*buffer;
	int		size;

	size = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!gnl_strchr(container, '\n') && size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(container);
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		container = gnl_strjoin(container, buffer);
	}
	free(buffer);
	return (container);
}

char	*gnl_polish(char *container)
{
	char	*str;
	int		i;

	i = 0;
	if (!container[i])
		return (NULL);
	while (container[i] != '\0' && container[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (container[i] != '\0' && container[i] != '\n')
	{
		str[i] = container[i];
		i++;
	}
	if (container[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*gnl_surplus(char *container)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (container[i] != '\0' && container[i] != '\n')
		i++;
	if (container[i] == '\0')
	{
		free(container);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(container) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (container[i] != '\0')
		str[j++] = container[i++];
	str[j] = '\0';
	free(container);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	container = gnl_traincontainer(fd, container);
	if (!container)
		return (NULL);
	line = gnl_polish(container);
	container = gnl_surplus(container);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("test/test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
		printf("%d->%s\n", lines++, line);
	close(fd);
	return (0);
}*/
