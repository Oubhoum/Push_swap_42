/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:38:33 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/05/02 15:29:40 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	stock_stack(t_stack **stack, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (i == 0)
		{
			*stack = malloc(sizeof(t_stack));
			(*stack)->content = ft_atoi(tab[i]);
			(*stack)->next = NULL;
		}
		else
		{
			ft_lstadd_back(stack, ft_lstnew(ft_atoi(tab[i])));
		}
		i++;
	}
}

static	void	free_table(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	main(int ac, char **av)
{
	char	**tab;
	char	*str;
	t_stack	*bs_stack;
	t_stack	*b_lst;

	b_lst = NULL;
	str = join_function(av);
	tab = ft_split(str, ' ');
	if ((ac > 1) && (repeated_item(tab) == 0 || check_is_int(tab) == 0
			|| check_befor_n_after_sign(str) == 0 || check_if_digit(tab) == 0))
	{
		return (free(str), free_table(tab), write(1, "Error\n", 6), exit(1), 0);
	}
	stock_stack(&bs_stack, tab);
	read_stdin(&bs_stack, &b_lst);
	if (check_sorting_bonus(bs_stack) == 0 && ft_lstsize(b_lst) == 0)
		return (write(1, "OK\n", 3), exit(0), 0);
	else
		return (write(1, "KO\n", 3), exit(0), 0);
	free(str);
	free_table(tab);
	return (0);
}
