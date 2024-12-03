/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:40:23 by jbeck             #+#    #+#             */
/*   Updated: 2023/06/23 11:47:33 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (dst[i] != '\0' && i < size)
	{
		i++;
	}
	while (src[k] != '\0' && i + k + 1 < size)
	{
		dst[i + k] = src[k];
		k++;
	}
	if (i != size)
	{
		dst[i + k] = '\0';
	}
	return (i + ft_strlen(src));
}
