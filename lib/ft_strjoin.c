/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:32:27 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/16 08:10:10 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_get_total_len(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	return (i);
}

static void	ft_cat(char *dest, const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = 0;
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	len = ft_get_total_len(s1, s2);
	dest = malloc(len * sizeof(char));
	if (!dest)
		return (NULL);
	ft_cat(dest, s1, s2);
	return (dest);
}
