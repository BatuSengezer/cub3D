/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:08:25 by jbeck             #+#    #+#             */
/*   Updated: 2023/06/23 11:46:38 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	i = 0;
	s = (char *) src;
	d = (char *) dest;
	if (dest == 0 && src == 0)
	{
		return (NULL);
	}
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
