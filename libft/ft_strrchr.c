/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:54:07 by jbeck             #+#    #+#             */
/*   Updated: 2023/06/23 11:47:58 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		ch;
	const char	*str;

	i = 0;
	ch = (char)c;
	while (s[i] != '\0')
	{
		i++;
	}
	while (i >= 0 && s[i] != ch)
	{
		i--;
	}
	if (s[i] == ch)
	{
		str = &s[i];
		return ((char *)str);
	}
	return (0);
}
