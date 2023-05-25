/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:23:56 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/04/12 17:51:41 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	all_the_greeters(int element, t_stack *lst)
{
	int		greeters;
	t_stack	*tmp;

	greeters = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->content > element)
			greeters++;
		tmp = tmp->next;
	}
	return (greeters);
}

static	int	min_of_table(int *table, int len)
{
	int	i;
	int	min;

	min = table[0];
	i = 1;
	while (i < len)
	{
		if (table[i] < min)
			min = table[i];
		i++;
	}
	return (min);
}

int	get_next(int element, t_stack *lst)
{
	t_stack		*tmp;
	int			*table;
	int			i;
	int			min;

	table = malloc(sizeof(int) * (all_the_greeters(element, lst) + 1));
	if (!table)
		return (0);
	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->content > element)
			table[i++] = tmp->content;
		tmp = tmp->next;
	}
	if (i == 0)
		return (free(table), get_min(&lst));
	table[i] = '\0';
	min = min_of_table(table, all_the_greeters(element, lst));
	free(table);
	return (min);
}

int	best_move(int element, t_stack *lst)
{
	int	size;
	int	index;
	int	best_move;

	size = ft_lstsize(lst);
	index = get_index(element, &lst);
	best_move = 0;
	if (index <= (size / 2))
		best_move = index;
	if (index > (size / 2))
		best_move = size - index;
	return (best_move);
}
