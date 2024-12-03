/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:56:38 by jbeck             #+#    #+#             */
/*   Updated: 2023/06/23 11:47:29 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	size;
	size_t	j;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
	{
		str[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j + i] = s2[i];
		i++;
	}
	str[j + i] = '\0';
	return (str);
}
