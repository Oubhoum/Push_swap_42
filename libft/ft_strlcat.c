/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:50:33 by aoubhoum          #+#    #+#             */
/*   Updated: 2022/11/11 00:55:48 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;
	size_t	j;

	i = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	j = dlen;
	if (destsize == 0)
		return (slen);
	if (destsize <= dlen)
		return (slen + destsize);
	if (destsize > dlen)
	{
		while ((i < destsize - j - 1) && src[i])
		{
			dest[dlen] = src[i];
			dlen++;
			i++;
		}
		dest[dlen] = '\0';
	}
	return (slen + j);
}
