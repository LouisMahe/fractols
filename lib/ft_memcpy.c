/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:46:10 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/08 10:56:13 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pt_dest;
	const unsigned char	*pt_src;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	pt_dest = (unsigned char *)dest;
	pt_src = (const unsigned char *)src;
	while (i < n)
	{
		pt_dest[i] = pt_src[i];
		i++;
	}
	return (dest);
}
