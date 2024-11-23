/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:07:02 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/14 11:51:01 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_free_fd(t_fdlist **fdlst, int fd)
{
	t_fdlist	*pt;
	t_fdlist	*previous;

	pt = *fdlst;
	previous = NULL;
	while (pt)
	{
		if (pt->fd == fd)
		{
			if (previous)
				previous->next = pt->next;
			else
				*fdlst = pt->next;
			free(pt->cache);
			free(pt);
			break ;
		}
		previous = pt;
		pt = pt->next;
	}
	return (1);
}

char	**ft_get_fd(t_fdlist **fdlst, int fd)
{
	t_fdlist	*pt;

	pt = *fdlst;
	while (pt && pt->fd != fd)
		pt = pt->next;
	if (!pt)
	{
		pt = malloc(sizeof(t_fdlist));
		if (!pt)
			return (NULL);
		pt->cache = NULL;
		pt->fd = fd;
		pt->next = *fdlst;
		*fdlst = pt;
	}
	return (&(pt->cache));
}

ssize_t	ft_read(char **cache, int fd)
{
	ssize_t	n_read;
	char	*new_cache;
	char	*buff;

	n_read = BUFFER_SIZE;
	if (ft_is_newl(*cache) >= 0)
		return (n_read);
	while (n_read == BUFFER_SIZE && ft_is_newl(*cache) < 0)
	{
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (-1);
		n_read = read(fd, buff, BUFFER_SIZE);
		buff[n_read] = 0;
		if (!(*cache))
			new_cache = ft_strjoin_gnl(buff, "");
		if (*cache)
		{
			new_cache = ft_strjoin_gnl(*cache, buff);
			free(buff);
		}
		*cache = new_cache;
	}
	return (n_read);
}

char	*ft_get_line(char **cache)
{
	char	*line;
	char	*new_cache;
	ssize_t	i;

	i = ft_is_newl(*cache);
	if (i < 0)
	{
		line = ft_strjoin_gnl(*cache, "");
		*cache = NULL;
	}
	else
	{
		line = ft_substr_gnl(*cache, 0, i + 1);
		if (!line)
			return (free(*cache), NULL);
		new_cache = ft_substr_gnl(*cache, i + 1, -1);
		free(*cache);
		*cache = new_cache;
		if (!*cache)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

char	*get_next_line(int fd, int close)
{
	static t_fdlist	*fdlst = NULL;
	char			**cache;
	char			*line;

	if (close)
	{
		ft_free_fd(&fdlst, fd);
		return (NULL);
	}
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	cache = ft_get_fd(&fdlst, fd);
	if (!cache)
		return (NULL);
	if (ft_read(cache, fd) < 0 && ft_free_fd(&fdlst, fd))
		return (NULL);
	line = ft_get_line(cache);
	if (!line || line[0] == 0)
	{
		ft_free_fd(&fdlst, fd);
		free(line);
		return (NULL);
	}
	return (line);
}
