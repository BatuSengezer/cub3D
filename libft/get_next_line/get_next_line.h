/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:05:30 by jbeck             #+#    #+#             */
/*   Updated: 2023/07/12 19:45:20 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_gstrchr(const char *s, int c);
char	*ft_gstrjoin(char *s1, char *s2);
char	*ft_getline(char *str);
char	*ft_startnext(char *to_read);
void	ft_gbzero(void *s, size_t n);
void	*ft_gmemset(void *s, int c, size_t n);
size_t	ft_gstrlen(const char *s);

#endif