/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:12:56 by jbeck             #+#    #+#             */
/*   Updated: 2023/07/13 13:26:08 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*s;

	tmp = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	if (s < tmp)
	{
		while (n--)
		{
			tmp[n] = s[n];
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}

// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	unsigned char	*d;
// 	unsigned char	*s;

// 	d = (unsigned char *)dst;
// 	s = (unsigned char *)src;
// 	if (!dst && !src)
// 		return (dst);
// 	if (src < dst)
// 		while (len--)
// 			d[len] = s[len];
// 	else
// 	while (len--)
// 			*d++ = *s++;
// 	return (dst);
// }
