/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speladea <speladea@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-14 14:44:49 by speladea          #+#    #+#             */
/*   Updated: 2024-06-14 14:44:49 by speladea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_txt(char *buffer, char *bookmark, int fd)
{
	size_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!bookmark)
			bookmark = ft_strdup("");
		tmp = bookmark;
		bookmark = ft_strjoin(tmp, buffer);
		free (tmp);
		if (!bookmark)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (bookmark);
}

static char	*ft_get_bookmark(char *get_txt)
{
	char	*bookmark;
	int		i;

	i = 0;
	if (!get_txt)
		return (NULL);
	while (get_txt[i] != '\0' && get_txt[i] != '\n')
		i++;
	if (get_txt[i] == '\0')
		return (NULL);
	i++;
	bookmark = ft_substr(get_txt, i, ft_strlen(get_txt) - i);
	if (!bookmark || *bookmark == '\0')
	{
		free (bookmark);
		bookmark = NULL;
	}
	get_txt[i] = '\0';
	return (bookmark);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*get_txt;
	static char	*bookmark = NULL;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (bookmark);
		bookmark = NULL;
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	get_txt = ft_get_txt(buffer, bookmark, fd);
	free (buffer);
	buffer = NULL;
	if (!get_txt)
		return (NULL);
	bookmark = ft_get_bookmark(get_txt);
	return (get_txt);
}

/* int	main(void)
{
	int	fd;
	char *line;

	fd = open("mali.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("line = %s", line);
		if (!line)
			break ;
		free(line);
	}
	close (fd);
} */
