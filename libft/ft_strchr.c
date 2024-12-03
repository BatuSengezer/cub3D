/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:09:26 by jbeck             #+#    #+#             */
/*   Updated: 2023/06/23 11:47:17 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	char		ch;
	const char	*str;

	i = 0;
	ch = (char)c;
	while (s[i] != '\0' && s[i] != ch)
	{
		i++;
	}
	if (s[i] == ch)
	{
		str = &s[i];
		return ((char *)str);
	}
	return (0);
}
