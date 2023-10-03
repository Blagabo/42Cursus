/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 08:42:13 by gblanco-          #+#    #+#             */
/*   Updated: 2023/09/26 11:14:37 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*line;
	char	*temp;
	char	*newline;
	size_t	line_length;

	line = NULL;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		newline = ft_strchr(buffer, '\n');
		if (newline != NULL)
		{
			line_length = newline - buffer;
			temp = line;
			line = malloc(line_length + 1);
			if (!line)
				return (NULL);
			strncpy(line, buffer, line_length);
			line[line_length] = '\0';
			if (temp)
			{
				line = realloc(line, line_length + ft_strlen(temp) + 1);
				if (!line)
					return (NULL);
				strcat(line, temp);
				free(temp);
			}
			return (line);
		}
		else
		{
			if (!line)
				line = ft_strdup(buffer);
			else
			{
				temp = line;
				line = malloc(ft_strlen(temp) + bytes_read + 1);
				if (!line)
					return (NULL);
				strcpy(line, temp);
				strcat(line, buffer);
				free(temp);
			}
		}
	}
	return (line);
}

int	main(void)
{
	int		archivo;
	char	*linea;

	archivo = open("test.txt", O_RDONLY);
	linea = get_next_line(archivo);
	printf("%s\n", linea);
	close(archivo);
	return (0);
}
