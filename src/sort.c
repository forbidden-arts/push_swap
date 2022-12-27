/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:00:22 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/27 16:27:40 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_control(t_stack **a, t_stack **b)
{
	if (ft_is_sorted(*a) || ft_stack_size(*a) == 1)
		return ;
	b = NULL;
	ft_assign_index(*a);
	if (ft_stack_size(*a) <= 3)
		ft_sort_mini(a);
}

void	ft_sort_mini(t_stack **a)
{
	if (ft_stack_size(*a) == 2)
		ft_swap_a(a);
	while (!ft_is_sorted(*a))
	{
		if ((*a)->index > (*a)->next->index && (*a)->index
			> (*a)->next->next->index)
			ft_rotate_a(a, 1);
		else if ((*a)->index > (*a)->next->next->index)
			ft_rotate_a(a, -1);
		else
			ft_swap_a(a);
	}
}

// static void	ft_sort_stacks(t_stack **a, t_stack **b);
