/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:54:15 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/08 10:52:18 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc( size_t count, size_t size)
{
	unsigned char	*pt;
	size_t			bytes;
	size_t			i;

	i = 0;
	bytes = count * size;
	if (size && bytes / size != count)
		return (NULL);
	pt = malloc(count * size * sizeof(char));
	if (!pt)
		return (NULL);
	while (i < size * count)
	{
		pt[i] = 0;
		i++;
	}
	return ((void *)pt);
}
