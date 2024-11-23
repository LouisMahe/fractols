/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:53:23 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/08 10:52:45 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_charset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_right_start(const char *s1, const char *set)
{
	int	count;

	count = 0;
	while (s1[count] && ft_is_charset(s1[count], set))
		count++;
	return (count);
}

static int	ft_left_end(const char *s1, const char *set)
{
	int	count;

	count = (int)ft_strlen(s1) - 1;
	while (count >= 0 && ft_is_charset(s1[count], set))
		count--;
	return (count);
}

static char	*ft_one_b(void)
{
	char	*pt;

	pt = malloc(sizeof(char));
	if (!pt)
		return (NULL);
	pt[0] = 0;
	return (pt);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t		start;
	size_t		end;
	size_t		i;
	char		*strim;

	if (!s1)
		return (NULL);
	start = ft_right_start(s1, set);
	if (start == ft_strlen(s1))
		return (ft_one_b());
	end = ft_left_end(s1, set);
	strim = malloc((end - start + 2) * sizeof(char));
	if (!strim)
		return (NULL);
	i = 0;
	while (i < end - start + 1)
	{
		strim[i] = s1[start + i];
		i++;
	}
	strim[i] = 0;
	return (strim);
}
