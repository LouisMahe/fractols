/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:27:29 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/05 14:24:34 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_type(char c)
{
	int	i;

	i = 0;
	while (FLAGS[i])
	{
		if (FLAGS[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printtype(char c, va_list *types)
{
	if (c == 'c')
		return (ft_printchar(va_arg(*types, int)));
	else if (c == 's')
		return (ft_printstr(va_arg(*types, char *)));
	else if (c == 'p')
		return (ft_printpt(va_arg(*types, uintptr_t)));
	else if (c == 'd')
		return (ft_printdecimal(va_arg(*types, int)));
	else if (c == 'i')
		return (ft_printdecimal(va_arg(*types, int)));
	else if (c == 'u')
		return (ft_printudecimal(va_arg(*types, unsigned int)));
	else if (c == 'x')
		return (ft_printlhexa(va_arg(*types, unsigned int)));
	else if (c == 'X')
		return (ft_printuhexa(va_arg(*types, unsigned int)));
	else
		return (ft_printpercent());
}

int	ft_printf(const char *input, ...)
{
	va_list	types;
	int		len;

	va_start (types, input);
	len = 0;
	if (!input)
		return (-1);
	while (*input)
	{
		while (*input && *input != '%')
		{
			len += ft_printchar(*input);
			input++;
		}
		if (*input == '%')
		{
			input++;
			if (ft_is_type(*input))
			{
				len += ft_printtype(*input, &types);
				input++;
			}
		}
	}
	return (len);
}
