/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 09:19:05 by aoubhoum          #+#    #+#             */
/*   Updated: 2022/11/10 10:55:37 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	long int	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_count(n);
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (ptr);
	ptr[i] = 0;
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	while (n > 0 && i--)
	{
		ptr[i] = n % 10 + '0';
		n = n / 10;
	}
	return (ptr);
}
