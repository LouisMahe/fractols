/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:19:23 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/23 14:26:24 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*pt;

	pt = malloc (sizeof(t_list));
	if (!pt)
		return (NULL);
	pt->content = content;
	pt->next = NULL;
	return (pt);
}
