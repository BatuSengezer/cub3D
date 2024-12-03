/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subsplit_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:35:39 by joschka           #+#    #+#             */
/*   Updated: 2023/12/08 11:15:24 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_subsplit.h"

void	initstruct(t_norm *s)
{
	s->i = 0;
	s->flag = 0;
	s->scount = 0;
	s->wcount = 0;
	s->j = 0;
}

int	quotesclosed(char const *str, char sub)
{
	int	quotes;
	int	i;

	i = 0;
	quotes = 0;
	while (str[i])
	{
		if (str[i] == sub)
			quotes++;
		i++;
	}
	if (quotes % 2 == 0)
		return (1);
	else
		return (0);
}

int	wlen(char const *ptr, char c)
{
	int	i;

	i = 0;
	while (ptr[i] != '\0' && ptr[i] != c)
	{
		i++;
	}
	return (i);
}

void	ft_freesubsplit(char **split)
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
