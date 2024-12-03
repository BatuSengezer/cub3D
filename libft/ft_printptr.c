/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:52:56 by jbeck             #+#    #+#             */
/*   Updated: 2023/06/23 11:43:39 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%p cast the pointer to unsigned long(int) and translate it to hexadecimal
void	ft_ptrtohex(unsigned long nb)
{
	if (nb > 15)
	{
		ft_ptrtohex(nb / 16);
		ft_ptrtohex(nb % 16);
	}
	else if (nb < 10)
	{
		nb = nb + '0';
		write(1, &nb, 1);
	}
	else
	{
		nb = nb - 10 + 'a';
		write(1, &nb, 1);
	}
}

int	ft_printptr(unsigned long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	ft_ptrtohex(nb);
	len += ft_hexlen(nb);
	return (len);
}
