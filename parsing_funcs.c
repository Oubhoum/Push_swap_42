/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:16:56 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/04/30 14:05:14 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_function(char **av)
{
	int		i;
	char	*string;
	char	*tmp;

	i = 1;
	string = ft_strdup("");
	if (!string)
		return (free(string), NULL);
	while (av[i])
	{
		check_empty_string(av[i]);
		tmp = string;
		string = ft_strjoin(string, av[i]);
		free(tmp);
		tmp = string;
		string = ft_strjoin(string, " ");
		free(tmp);
		i++;
	}
	return (string);
}

int	check_if_digit(char **tab)
{
	int	i;
	int	j;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((tab[i][j] >= '0' && tab[i][j] <= '9')
			|| tab[i][j] == '+' || tab[i][j] == '-'
			|| (tab[i][j] >= '\t' && tab[i][j] <= '\r') || tab[i][j] == ' ')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_befor_n_after_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
		{
			i++;
			if (!ft_isdigit(str[i]))
				return (0);
			i -= 2;
			if (i >= 0)
			{
				if (ft_isdigit(str[i]) && i < 0)
					return (0);
			}
			i++;
		}
		i++;
	}
	return (1);
}

int	repeated_item(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (ft_atoi(array[i]) == ft_atoi(array[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_sorting(char	**array)
{
	int	i;
	int	j;
	int	nbr;

	i = 0;
	nbr = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (ft_atoi(array[i]) > ft_atoi(array[j]))
				nbr = 1;
			j++;
		}
		i++;
	}
	return (nbr);
}
