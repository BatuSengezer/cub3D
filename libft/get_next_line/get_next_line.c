/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:05:47 by jbeck             #+#    #+#             */
/*   Updated: 2023/07/12 19:46:01 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gstrchr(const char *s, int c)
{
	int			i;
	char		ch;
	const char	*str;

	if (!s)
		return (0);
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

char	*ft_startnext(char *to_read)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (!to_read)
		return (NULL);
	while (to_read[i] && to_read[i] != '\n')
		i++;
	if (!to_read[i])
	{
		free(to_read);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_gstrlen(to_read) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = -1;
	while (to_read[i + j++])
		str[j] = to_read[i + j];
	str[j] = '\0';
	free(to_read);
	return (str);
}

char	*ft_getline(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	ft_sweetsilence(char *line, char *to_read)
{
	free(line);
	ft_gbzero(to_read, ft_gstrlen(to_read));
}

char	*get_next_line(int fd)
{
	static char	*to_read;
	char		*line;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!line)
		return (NULL);
	count = 1;
	while (!(ft_gstrchr(to_read, '\n')) && count != 0)
	{
		count = read(fd, line, BUFFER_SIZE);
		if (count == -1)
		{
			ft_sweetsilence(line, to_read);
			return (NULL);
		}
		line[count] = '\0';
		to_read = ft_gstrjoin(to_read, line);
	}
	free(line);
	line = ft_getline(to_read);
	to_read = ft_startnext(to_read);
	return (line);
}
