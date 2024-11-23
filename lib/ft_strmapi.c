/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:53:51 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/07 14:39:59 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*sf;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	i = 0;
	sf = malloc(len * sizeof(char));
	if (!sf)
		return (NULL);
	while (i < len - 1)
	{
		sf[i] = f(i, s[i]);
		i++;
	}
	sf[i] = 0;
	return (sf);
}
