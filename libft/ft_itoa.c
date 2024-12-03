/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:31:50 by jbeck             #+#    #+#             */
/*   Updated: 2023/06/23 11:45:38 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getlen(long n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	if (n == 0)
		return (1);
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	size++;
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = ft_getlen(nb);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	if (nb == 0)
		str[0] = 48;
	str[len] = '\0';
	len--;
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	while (nb != 0)
	{
		str[len] = (nb % 10) + 48;
		nb = nb / 10;
		len--;
	}
	return (str);
}
