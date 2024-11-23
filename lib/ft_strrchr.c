/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:13:20 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/08 11:02:18 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*pt;

	pt = NULL;
	while (*str)
	{
		if (*str == (unsigned char)c)
			pt = (char *) str;
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (pt);
}
