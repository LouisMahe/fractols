/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:37:13 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/08 10:56:20 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*pt_dest;

	pt_dest = (unsigned char *) dest;
	if (!pt_dest && !(unsigned char *)src)
		return (NULL);
	if (pt_dest > (unsigned char *)src)
	{
		i = n - 1;
		while (i >= 0)
		{
			pt_dest[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while ((size_t)i < n)
		{
			pt_dest[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
