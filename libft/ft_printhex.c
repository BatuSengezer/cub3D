/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:56:10 by jbeck             #+#    #+#             */
/*   Updated: 2023/06/23 11:43:32 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%x & %X
void	ft_dectohex(unsigned int nb, const char specifier)
{
	if (nb > 15)
	{
		ft_dectohex(nb / 16, specifier);
		ft_dectohex(nb % 16, specifier);
	}
	else if (nb < 10)
	{
		nb = nb + '0';
		write(1, &nb, 1);
	}
	else
	{
		if (specifier == 'x')
		{
			nb = nb - 10 + 'a';
			write(1, &nb, 1);
		}
		else if (specifier == 'X')
		{
			nb = nb - 10 + 'A';
			write(1, &nb, 1);
		}
	}
}

int	ft_printhex(unsigned int nb, const char specifier)
{
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_dectohex(nb, specifier);
	return (ft_hexlen(nb));
}
