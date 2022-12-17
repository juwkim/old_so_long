/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 00:47:12 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/16 20:07:04 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(char *buf, char **rest, ssize_t read_size, char **rtn)
{
	int		idx;
	char	*temp;

	buf[read_size] = '\0';
	idx = ft_strchr(buf, '\n') - buf;
	if (idx != -1 && buf[idx + 1])
	{
		*rest = ft_substr(buf, idx + 1, read_size - idx - 1);
		buf[idx + 1] = '\0';
	}
	if (*rtn)
	{
		temp = ft_strjoin(*rtn, buf);
		free(*rtn);
		*rtn = temp;
	}
	else
		*rtn = ft_strdup(buf);
	return (idx != -1);
}

int	check_rest(char **rest, char **rtn)
{
	int		idx;
	int		len;
	char	*temp;

	len = ft_strlen(*rest);
	idx = ft_strchr(*rest, '\n') - *rest;
	if (-1 < idx && idx < len - 1)
	{
		*rtn = ft_substr(*rest, 0, idx + 1);
		temp = ft_substr(*rest, idx + 1, len - idx - 1);
		free(*rest);
		*rest = temp;
		return (1);
	}
	*rtn = *rest;
	*rest = NULL;
	return (idx != -1);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buf;
	char		*rtn;
	ssize_t		read_size;

	rtn = NULL;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (rest && check_rest(&rest, &rtn))
		return (rtn);
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0 && get_line(buf, &rest, read_size, &rtn) == 0)
		read_size = read(fd, buf, BUFFER_SIZE);
	free(buf);
	return (rtn);
}
