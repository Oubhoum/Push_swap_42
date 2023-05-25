/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:17:58 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/05/02 17:18:38 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_empty_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32)
			return (1);
		i++;
	}
	return (write(2, "Error\n", 6), exit(1), 0);
}

int	check_is_int(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		if (split[i][0] == '+' || split[i][0] == '-')
				j++;
		while (split[i][j])
		{
			if (split[i][j] < '0' || split[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!check_if_digit(str)
				|| !check_befor_n_after_sign(&str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	if (!repeated_item(str))
		return (0);
	return (1);
}
