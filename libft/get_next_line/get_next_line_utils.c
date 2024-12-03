/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:06:30 by jbeck             #+#    #+#             */
/*   Updated: 2023/07/12 19:51:10 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gstrlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_gmemset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (n > 0)
	{
		str[n - 1] = c;
		n--;
	}
	return (s);
}

void	ft_gbzero(void *s, size_t n)
{
	ft_gmemset(s, '\0', n);
}

void	ft_writetostr(char *s1, char *s2, char *str)
{
	size_t	i;
	size_t	j;

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
}

char	*ft_gstrjoin(char *s1, char *s2)
{
	char	*str;
	size_t	size;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	size = ft_gstrlen(s1) + ft_gstrlen(s2);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	ft_writetostr(s1, s2, str);
	free(s1);
	return (str);
}
