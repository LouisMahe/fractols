/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:30:32 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/08 11:02:11 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_egal(const char *str, const char *to_find)
{
	while (*str && *to_find)
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
	}
	return (*to_find == 0);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	l_str;
	size_t	l_to_find;
	size_t	i;

	if (!str && !n)
		return (NULL);
	if (!*to_find)
		return ((char *)str);
	l_str = ft_strlen(str);
	l_to_find = ft_strlen(to_find);
	if (l_to_find > n || l_to_find > l_str)
		return (0);
	i = 0;
	while (str[i] && i < n + 1 - l_to_find)
	{
		if (str[i] == *to_find && ft_is_egal(str + i, to_find))
			return ((char *)str + i);
		i++;
	}
	return (0);
}
