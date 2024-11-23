/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:39:55 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/06 16:51:50 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_display_digit(long n, int fd)
{
	char	temp;

	temp = 0;
	if (n >= 10)
		ft_display_digit(n / 10, fd);
	temp = (n % 10) + '0';
	write(fd, &temp, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	ft_display_digit(n, fd);
}
