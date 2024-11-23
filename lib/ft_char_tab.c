/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:04:40 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/08 16:57:56 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_display_char_tab(char **tab)
{
	int	i;

	if (!tab || !(*tab))
		return ;
	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == 0)
			printf("chaine vide\n");
		else
			ft_printf("%s\n", tab[i]);
		i++;
	}
}

void	ft_free_char_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
