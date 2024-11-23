/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:22:12 by lmahe             #+#    #+#             */
/*   Updated: 2023/11/27 08:53:53 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include<stdint.h>

# define FLAGS "cspdiuxX%"
# define HEXA 16
# define HEXAL "0123456789abcdef"
# define HEXAU "0123456789ABCDEF"

int	ft_printchar(int c);
int	ft_printdecimal(int x);
int	ft_printint(int x);
int	ft_printpercent(void);
int	ft_printpt(uintptr_t p);
int	ft_printstr(char *s);
int	ft_printudecimal(unsigned int x);
int	ft_printlhexa(unsigned int x);
int	ft_printuhexa(unsigned int x);
int	ft_printf(const char *input, ...);

#endif
