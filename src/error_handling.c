/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:03:53 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/20 12:12:19 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tab_unwind(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

void	ft_exit_on_error(t_stack **a, t_stack **b)
{
	if (a)
		ft_free_stack(a);
	if (b)
		ft_free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_stk_chk_valid(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+')
				&& ft_isdigit(argv[i][j + 1]))
				j++;
			if (!(ft_isdigit(argv[i][j]) || argv[i][j] == 32))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	(*stack) = NULL;
}

void	ft_chk_dup_stack(t_stack *a)
{
	t_stack	*tmp;

	while (a->next)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->value == tmp->value)
				ft_exit_on_error(&a, NULL);
			tmp = tmp->next;
		}
		a = a->next;
	}
}
