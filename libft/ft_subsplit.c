/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:57:17 by joschka           #+#    #+#             */
/*   Updated: 2023/12/08 11:25:41 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_subsplit.h"

static int	ft_subsplitsize(char const *str, char c, char sub)
{
	t_norm	s;

	initstruct(&s);
	while (str[s.i])
	{
		if (str[s.i] != c && s.flag == 0 && str[s.i] != sub)
		{
			s.wcount++;
			s.flag = 1;
		}
		else if (str[s.i] == sub)
		{
			s.scount++;
			s.flag = 1;
			if (s.scount % 2 == 0 && s.scount != 0)
				s.wcount++;
		}
		else if (str[s.i] == c && s.scount % 2 == 0)
		{
			s.flag = 0;
		}
		s.i++;
	}
	return (s.wcount);
}

static int	checksubstr(char const *s, char sub)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == sub && s[i + 1] == sub)
			return (1);
		i++;
	}
	return (0);
}

static int	checks(char const *s, char c, char sub)
{
	int	size;

	size = ft_subsplitsize(s, c, sub);
	if (!s || !*s || !size)
		return (1);
	else if (!quotesclosed(s, sub) || !sub || checksubstr(s, sub))
		return (2);
	else
		return (0);
}

static int	ft_fillsubsplit(char const *s, char c, char **split, char sub)
{
	t_norm	w;

	initstruct(&w);
	while (s[w.i])
	{
		if (s[w.i] != c && w.flag == 0)
		{
			if (s[w.i] == sub)
			{
				split[w.j] = ft_substr(s, w.i + 1, (wlen(&s[w.i + 1], sub)));
				w.i += wlen(&s[w.i] + 1, sub) + 1;
			}
			else
				split[w.j] = ft_substr(s, w.i, (wlen(&s[w.i], c)));
			if (split[w.j] == NULL)
				return (1);
			w.flag = 1;
			w.j++;
		}
		else if (s[w.i] == c)
			w.flag = 0;
		w.i++;
	}
	split[w.j] = 0;
	return (0);
}

char	**ft_subsplit(char const *s, char c, char sub)
{
	char	**split;

	if (checks(s, c, sub))
	{
		if (checks(s, c, sub) == 1)
			return (NULL);
		else if (checks(s, c, sub) == 2)
		{
			split = ft_split(s, c);
			return (split);
		}
	}
	split = malloc((ft_subsplitsize(s, c, sub) + 1) * (sizeof(char *)));
	if (split == NULL)
		return (NULL);
	if (ft_fillsubsplit(s, c, split, sub))
	{
		ft_freesubsplit(split);
		return (NULL);
	}
	return (split);
}
