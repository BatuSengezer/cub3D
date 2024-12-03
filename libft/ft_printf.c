/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:48:12 by joschka           #+#    #+#             */
/*   Updated: 2023/06/23 11:43:22 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// get and pass Argument
int	ft_checktype(va_list args, const char vtype)
{
	int	count;

	count = 0;
	if (vtype == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (vtype == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (vtype == 'd' || vtype == 'i')
		count += ft_printnbr(va_arg(args, int));
	else if (vtype == 'x' || vtype == 'X')
		count += ft_printhex(va_arg(args, unsigned int), vtype);
	else if (vtype == 'p')
		count += ft_printptr(va_arg(args, unsigned long));
	else if (vtype == 'u')
		count += ft_printuint(va_arg(args, unsigned int));
	else if (vtype == '%')
		count += write(1, "%", 1);
	return (count);
}

// well...ft_printf
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		num_printed;

	i = 0;
	num_printed = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			num_printed += ft_checktype(args, str[i]);
			i++;
		}
		else
		{
			num_printed += ft_printchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (num_printed);
}
