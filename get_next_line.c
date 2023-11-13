/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:48:34 by wiljimen          #+#    #+#             */
/*   Updated: 2023/11/13 12:21:11 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_auxwrite(int fd, char *aux)
{
	char	*line;
	int		read_bytes;

	read_bytes = 1;
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
	{
		return (NULL);
	}
	while (!ft_strchr(aux, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, line, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(line);
			return (NULL);
		}
		line[read_bytes] = '\0';
		ft_strjoin(aux, line);
	}
	free(line);
	return (aux);
}

char	*get_next_line(int fd)
{
	char		*aux[4096];
	static char	*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE == INT_MAX)
	{
		return (NULL);
	}
	aux[fd] = ft_auxwrite(fd, aux[fd]);
	result = ft_strcprinter(aux[fd]);
	free(aux);
	return (result);
}
