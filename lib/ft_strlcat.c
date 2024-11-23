/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:21:11 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/08 11:01:33 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	l_src;
	size_t	l_dest;
	size_t	i;

	l_src = ft_strlen(src);
	if (!dest && size == 0)
		return (l_src);
	l_dest = ft_strlen(dest);
	i = 0;
	if (size <= l_dest)
		return (size + l_src);
	while (src[i] && i < size - l_dest - 1)
	{
		dest[i + l_dest] = src[i];
		i++;
	}
	dest[i + l_dest] = 0;
	return (l_dest + l_src);
}
