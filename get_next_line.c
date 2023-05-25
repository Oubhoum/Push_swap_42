/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:43:01 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/04/28 20:24:01 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*return_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (ft_substr(str, 0, (i + 1)));
}

static	char	*ftt_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

static	char	*return_after_line(char *s)
{
	char	*after;
	int		i;
	int		j;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	j = i + 1;
	while (s[i] != '\0')
		i++;
	after = ft_substr(s, j, (i - j));
	free(s);
	return (after);
}

static char	*ft_allocation(char *str)
{
	if (!str)
	{
		str = (char *)malloc(1);
		str[0] = '\0';
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char				*buffer;
	char				*line;
	static char			*save;
	ssize_t				byte;

	byte = 1;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!save)
		save = ft_allocation(save);
	while (find_back_slash_n(save) == 0 && byte != 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
			return (free(buffer), free(save), save = NULL);
		buffer[byte] = '\0';
		save = ftt_strjoin(save, buffer);
	}
	free(buffer);
	line = return_line(save);
	save = return_after_line(save);
	return (line);
}
