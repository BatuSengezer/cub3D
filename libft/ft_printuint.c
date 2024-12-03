/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:47:37 by jbeck             #+#    #+#             */
/*   Updated: 2023/06/23 11:43:46 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %u
int	ft_uintlen(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

char	*ft_uitoa(unsigned int nb)
{
	char	*str;
	int		len;

	len = ft_uintlen(nb);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	if (nb == 0)
		str[0] = 48;
	str[len] = '\0';
	len--;
	while (nb != 0)
	{
		str[len] = (nb % 10) + 48;
		nb = nb / 10;
		len--;
	}
	return (str);
}

int	ft_printuint(unsigned int nb)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_uitoa(nb);
	count = ft_printstr(str);
	free(str);
	return (count);
}
