/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:00:04 by aoubhoum          #+#    #+#             */
/*   Updated: 2022/11/09 13:37:35 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*str11;
	unsigned char	*str22;
	size_t			i;

	if (!str1 && !str2)
		return (0);
	str11 = (unsigned char *) str1;
	str22 = (unsigned char *) str2;
	i = 0;
	while (i < n)
	{
		if (str11[i] != str22[i])
			return (str11[i] - str22[i]);
		i++;
	}
	return (0);
}
