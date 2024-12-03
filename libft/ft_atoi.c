/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:31:29 by jbeck             #+#    #+#             */
/*   Updated: 2023/06/23 11:44:05 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_whitespace(const char *str)
{
	int			i;
	const char	*bspc;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	bspc = &str[i];
	return (bspc);
}

static int	ft_isneg(const char *str, int *pti)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			k++;
		}
		i++;
	}
	*pti = i;
	return (k);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	*pti;
	int	result;
	int	neg;

	result = 0;
	i = 0;
	pti = &i;
	str = ft_whitespace(str);
	neg = ft_isneg(str, pti);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	if (neg == 1)
		result *= -1;
	return (result);
}
