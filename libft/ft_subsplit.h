/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subsplit.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschka <joschka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:41:44 by joschka           #+#    #+#             */
/*   Updated: 2023/12/08 11:15:38 by joschka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUBSPLIT_H
# define FT_SUBSPLIT_H

# include "libft.h"

typedef struct s_norm
{
	int	i;
	int	flag;
	int	wcount;
	int	scount;
	int	j;
}			t_norm;

char	**ft_subsplit(char const *s, char c, char sub);
int		quotesclosed(char const *str, char sub);
void	initstruct(t_norm *s);
int		wlen(char const *ptr, char c);
void	ft_freesubsplit(char **split);

#endif