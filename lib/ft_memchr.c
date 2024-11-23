/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:06:35 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/07 12:01:03 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*pt;

	i = 0;
	pt = (unsigned char *)s;
	while (i < n)
	{
		if (*pt == (unsigned char)c)
			return (pt);
		pt++;
		i++;
	}
	return (NULL);
}
