/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:04:04 by jereverd          #+#    #+#             */
/*   Updated: 2021/11/29 16:04:06 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char 	*ft_save_rest(char *cand)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (cand[i] && cand[i] != '\n')
	{
		i++;
		if (!cand[i])
		{
			free(cand);
			return (NULL);
		}
	}
	rest = malloc(sizeof(char) * ft_strlen(cand) - i + 1);
	if (!rest)
		return (NULL);
	i++;
	while (cand[i])
	{
		rest[j] = cand[i];
		i++;
		j++;
	}
	rest[j] = '\0';
	free(cand);
	return (rest);
}

char 	*ft_get_line(char *cand)
{
	int		i;
	char	*line;

	i = 0;
	if (!cand[i])
		return (NULL);
	while (cand[i] && cand[i] != '\n')
		i++;
	if (cand[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (cand[i] && cand[i] != '\n')
	{
		line[i] = cand[i];
		i++;
	}
	if (cand[i] == '\n')
		line[i] = cand[i];
	i++;
	line[i] = '\0';
	return (line);
}

char	*ft_find_cand(int fd, char *cand)
{
	char	buff[BUFFER_SIZE + 1];
	int 	read_ret;

	read_ret = 1;
	while (!ft_strchr(cand, '\n') && read_ret != 0)
	{
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		buff[read_ret] = '\0';
		cand = ft_strjoin(cand, buff);
	}
	return (cand);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*cand;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cand = ft_find_cand(fd, cand);
	if (!cand)
		return (NULL);
	line = ft_get_line(cand);
	cand = ft_save_rest(cand);
	return (line);
}