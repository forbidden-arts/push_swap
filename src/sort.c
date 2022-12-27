/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:00:22 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/27 18:55:00 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_control(t_stack **a, t_stack **b)
{
	int	size;

	*b = NULL;
	size = ft_stack_size(*a);
	if (ft_is_sorted(*a) || size == 1)
		return ;
	ft_assign_index(*a);
	if (size <= 3)
		ft_sort_mini(a);
	// else
	// {
	// 	ft_prescreen(a);
	// 	ft_sort_stacks(a, b, size);
	// }
}

void	ft_sort_mini(t_stack **a)
{
	if (ft_stack_size(*a) == 2)
		ft_do_op(a, NULL, "sa");
	while (!ft_is_sorted(*a))
	{
		if ((*a)->index > (*a)->next->index && (*a)->index
			> (*a)->next->next->index)
			ft_do_op(a, NULL, "ra");
		else if ((*a)->index > (*a)->next->next->index)
			ft_do_op(a, NULL, "rra");
		else
			ft_do_op(a, NULL, "sa");
	}
}

	//TODO:	move AT MOST size/2 to B
	//		nums can be moved to B only once
	//		B needs to be descending, take advantage of the double actions when available
	//		recursively call self

// void	ft_sort_stacks(t_stack **a, t_stack **b, int size)
// {
// 	// Fill B
// 	while (*a && ft_stack_size(*b) <= size / 2)
// 	{
// 		if (!(*a)->pushed)
// 			ft_push_b(a, b);
// 		(*a) = (*a)->next;
// 	}
// }

// void	ft_prescreen(t_stack **a)
// {
// 	while ((*a)->next)
// 	{
// 		if ((*a)->index + 1 == (*a)->next->index)
// 		{
// 			(*a)->pushed = 1;
// 			(*a)->next->pushed = 1;
// 		}
// 		(*a) = (*a)->next;
// 	}
// }
