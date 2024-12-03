/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:03:30 by jbeck             #+#    #+#             */
/*   Updated: 2023/12/07 15:28:06 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *str, ...);
int	ft_printuint(unsigned int nb);
int	ft_printptr(unsigned long nb);
int	ft_printhex(unsigned int nb, const char specifier);
int	ft_printnbr(int nb);
int	ft_printstr(char *str);
int	ft_printchar(int c);
int	ft_hexlen(unsigned long nb);

#endif