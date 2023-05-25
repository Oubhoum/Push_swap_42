/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:44:45 by aoubhoum          #+#    #+#             */
/*   Updated: 2022/11/10 09:18:30 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (!dst && !src)
		return (dst);
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
		while (len--)
			*(s1 + len) = *(s2 + len);
	return (s1);
}
