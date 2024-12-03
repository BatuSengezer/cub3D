/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:05:40 by jbeck             #+#    #+#             */
/*   Updated: 2024/11/14 17:56:49 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlen(char const *ptr, char c)
{
	int	i;

	i = 0;
	while (ptr[i] != '\0' && ptr[i] != c)
	{
		i++;
	}
	return (i);
}

static int	ft_splitsize(char const *str, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (str[i] == c)
		{
			flag = 0;
		}
		i++;
	}
	return (count);
}

static void	ft_freesplit(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	ft_fillsplit(char const *s, char c, char **split, int *ptr)
{
	int		i;
	int		flag;
	int		j;

	i = 0;
	flag = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			split[j] = ft_substr(s, i, (ft_getlen(&s[i], c)));
			if (split[j] == NULL)
			{
				*ptr = 1;
				return ;
			}
			flag = 1;
			j++;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	split[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		check;
	int		size;

	if (!s || !*s)
		return (NULL);
	check = 0;
	size = ft_splitsize(s, c);
	if (size == 0)
		return (NULL);
	split = malloc((size + 1) * (sizeof(char *)));
	if (split == NULL)
		return (NULL);
	ft_fillsplit(s, c, split, &check);
	if (check)
	{
		ft_freesplit(split);
		return (NULL);
	}
	return (split);
}
