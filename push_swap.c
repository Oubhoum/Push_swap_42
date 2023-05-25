/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:02:13 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/05/02 17:01:04 by aoubhoum         ###   ########.fr       */
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
			ft_lstadd_back(stack, ft_lstnew(ft_atoi(tab[i])));
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

int	main(int argc, char **argv)
{
	char	**tab;
	char	*str;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	str = join_function(argv);
	tab = ft_split(str, ' ');
	if ((argc > 1) && (repeated_item(tab) == 0 || check_is_int(tab) == 0
			|| check_befor_n_after_sign(str) == 0 || check_if_digit(tab) == 0))
	{
		free(str);
		free_table(tab);
		return (write(2, "Error\n", 6), exit(1), 0);
	}
	if (!check_sorting(tab))
		exit(0);
	stock_stack(&stack_a, tab);
	who_is_sorting(ft_lstsize(stack_a), stack_a, stack_b);
	free(str);
	free_table(tab);
	return (0);
}
