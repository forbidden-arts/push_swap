/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:00:22 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/30 16:42:18 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_control(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stack_size(*a);
	if (ft_is_sorted(*a) || size == 1)
		return ;
	ft_assign_index(*a);
	if (size <= 3)
		ft_sort_mini(a);
	else
	{
		// ft_prescreen(*a); NOT SURE THIS IS NEEDED.
		ft_sort_stacks(a, b, size);
		// ft_push_stack(b, a);
	}
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

void	ft_sort_stacks(t_stack **a, t_stack **b, int size)
{
	int	index;

	index = 1;
	// ft_printf("size: %d\n", size);
	// ft_printf("%d", ft_get_pos((*a), 1));
	// pause();
	while (size > 3 && !ft_is_sorted(*a))
	{
		ft_push_index(a, b, index);
		ft_do_op(a, b, PA);
		index++;
		size--;
	}
	ft_sort_mini(a);
	while (*b)
	{
		ft_do_op(a, b, PB);
	}
}

void	ft_push_index(t_stack **a, t_stack **b, int i)
{
	while ((*a)->index != i)
	{
		if (ft_get_pos(*a, i) <= ft_stack_size(*a) / 2)
			ft_do_op(a, b, RA);
		else
			ft_do_op(a, b, RRA);
	}
}
