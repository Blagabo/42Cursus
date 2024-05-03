/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 08:42:13 by gblanco-          #+#    #+#             */
/*   Updated: 2024/05/03 11:48:25 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *rest)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && ft_strchr(rest, '\n') == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(rest);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		rest = ft_strjoin(rest, buffer);
	}
	free(buffer);
	return (rest);
}

static char	*extract_line(char *rest)
{
	int		i;
	char	*line;

	i = 0;
	if (!rest || rest[0] == '\0')
		return (NULL);
	while (rest[i] != '\n' && rest[i] != '\0')
		i++;
	if (rest[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (rest[i] != '\n' && rest[i] != '\0')
	{
		line[i] = rest[i];
		++i;
	}
	if (rest[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_rest(char *rest)
{
	int		i;
	int		k;
	char	*rest_caract;

	i = 0;
	while (rest[i] != '\0' && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	rest_caract = malloc(sizeof(char) * (ft_strlen(rest) - i + 1));
	if (!rest_caract)
		return (NULL);
	k = 0;
	++i;
	while (rest[i] != '\0')
		rest_caract[k++] = rest[i++];
	rest_caract[k] = '\0';
	free(rest);
	return (rest_caract);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	rest = read_file(fd, rest);
	if (!rest)
		return (NULL);
	line = extract_line(rest);
	rest = update_rest(rest);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
}
*/