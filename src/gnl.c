/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:16:07 by abollen           #+#    #+#             */
/*   Updated: 2022/01/15 10:37:04 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_nlcheck(char	*text)
{
	int	i;

	i = -1;
	if (!text)
		return (-1);
	while (text[++i])
	{
		if (text[i] == '\n')
			return (i);
	}
	return (-1);
}

static char	*ft_free(char *str1, char *str2)
{
	if (str1)
		free (str1);
	if (str2)
		free (str2);
	return (NULL);
}

static int	ft_leftover_manager(char **line, char **leftover)
{
	*line = ft_strdup(*leftover);
	free(*leftover);
	*leftover = NULL;
	if (!(*line))
		return (0);
	return (1);
}

static char	*output(char *line, char **leftover)
{
	int		i;
	int		j;
	char	*dest;

	i = 1;
	while (line[i - 1] != '\n' && line[i])
		i++;
	j = i;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (ft_free(line, NULL));
	dest[i] = '\0';
	while (--i >= 0)
		dest[i] = line[i];
	if ((int)ft_strlen(line) > j)
	{
		*leftover = ft_strdup(line + j);
		if (!*leftover)
			return (ft_free(line, dest));
	}
	free(line);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		buffer[1000001];
	char		*line;
	int			ret;

	if (fd < 0 || 10 < 1 || read(fd, buffer, 0))
		return (NULL);
	line = NULL;
	ret = 1000000;
	while (ft_nlcheck(line) == -1 && ret == 1000000)
	{
		if (leftover)
			if (ft_leftover_manager(&line, &leftover) == 0)
				return (NULL);
		ft_bzero(buffer, 1000001);
		if (ft_nlcheck(line) == -1)
			ret = read(fd, buffer, 1000000);
		if (ret > 0)
			line = gnl_strjoin(line, (const char *)buffer);
		else if (ret == 0 && !line)
			return (NULL);
		if (!line)
			return (NULL);
	}
	return (output(line, &leftover));
}
