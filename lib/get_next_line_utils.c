/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:28:42 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/29 09:30:51 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

ssize_t	ft_is_newl(char *s)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen_gnl(s1);
	j = ft_strlen_gnl(s2);
	str = malloc ((i + j + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	free(s1);
	return (str);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	size_t	new_len;
	size_t	i;
	char	*new_s;

	if (!s || start > ft_strlen_gnl(s))
		new_len = 0;
	else
	{
		new_len = ft_strlen_gnl(s + start);
		if (new_len > len)
			new_len = len;
	}
	new_s = malloc ((new_len + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (i < new_len)
	{
		new_s[i] = s[start + i];
		i++;
	}
	new_s[i] = 0;
	return (new_s);
}
