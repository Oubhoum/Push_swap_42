/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:08:29 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/03/13 20:52:36 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (dest == NULL)
	{
		free(dest);
		return (NULL);
	}
	ft_memcpy(dest, s1, ft_strlen(s1) + 1);
	return (dest);
}
