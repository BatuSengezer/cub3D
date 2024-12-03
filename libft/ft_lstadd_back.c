/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:36:01 by jbeck             #+#    #+#             */
/*   Updated: 2023/06/23 11:45:43 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*run;

	if (!new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		run = ft_lstlast(*lst);
		run->next = new;
	}
}
