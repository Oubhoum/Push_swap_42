/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:29:08 by aoubhoum          #+#    #+#             */
/*   Updated: 2022/11/11 13:01:23 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	lenght;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	lenght = ft_strlen(s1);
	i = 0;
	j = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (lenght > i && ft_strchr(set, s1[lenght - 1]))
		lenght--;
	trim = ft_substr(s1, i, lenght - i);
	return (trim);
}
