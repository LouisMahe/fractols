/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:59:32 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/16 09:32:06 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (1);
}

static int	ft_get_wr_nb(const char *s, char c)
{
	int	n;

	n = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			n++;
		while (*s && *s != c)
			s++;
	}
	return (n + 1);
}

static char	*ft_get_word(const char *s, int *n, char c)
{
	int		len;
	int		j;
	char	*word;

	len = 0;
	j = 0;
	while (s[*n] == c && s[*n])
		*n = *n + 1;
	while (s[*n + len] != c && s[*n + len])
		len++;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (j < len)
	{
		word[j] = s[*n];
		j++;
		*n = *n + 1;
	}
	word[j] = 0;
	return (word);
}

char	**ft_split(const char *s, char c)
{
	int		w_nb;
	int		i;
	char	**tab;
	int		n;

	if (!s)
		return (NULL);
	w_nb = ft_get_wr_nb(s, c);
	tab = malloc(w_nb * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	n = 0;
	while (i < w_nb - 1)
	{
		tab[i] = ft_get_word(s, &n, c);
		if (tab[i] == NULL && ft_free(tab))
			return (NULL);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
