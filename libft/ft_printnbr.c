/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:57:57 by jbeck             #+#    #+#             */
/*   Updated: 2023/06/23 11:43:35 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %d & %i
int	ft_printnbr(int nb)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa(nb);
	count = ft_printstr(str);
	free(str);
	return (count);
}
