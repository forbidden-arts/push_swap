/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:00:22 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/16 12:18:32 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_control(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_s_size(*a);
	if (ft_is_sorted(*a, 1) || size == 1)
		return ;
	ft_assign_index(*a);
	if (size <= 3)
		ft_sort_mini_a(a, b);
	else if (size < 6)
	{
		while (ft_s_size(*a) > 3)
			ft_do_op(a, b, PB);
		ft_sort_mini_a(a, b);
		while (ft_s_size(*b))
			ft_sort_small(a, b);
		ft_top_a(a, 1);
	}
	else
	{
		ft_quick(a, b);
	}
}

void	ft_sort_mini_a(t_stack **a, t_stack **b)
{
	if (ft_s_size(*a) == 2)
		ft_do_op(a, b, SA);
	while (!ft_is_sorted(*a, 1))
	{
		if ((*a)->index > (*a)->next->index && (*a)->index
			> (*a)->next->next->index)
			ft_do_op(a, b, RA);
		else if ((*a)->index > (*a)->next->next->index)
			ft_do_op(a, b, RRA);
		else
			ft_do_op(a, b, SA);
	}
}

void	ft_sort_small(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = ft_stack_last(*a);
	if (ft_s_size(*b) > 1 && (*b)->index < (*b)->next->index)
		ft_do_op(a, b, SB);
	else if (ft_is_sorted(*a, 1) && ((*b)->index < ft_find_min(*a)
			|| (*b)->index > ft_find_max(*a)))
		ft_do_op(a, b, PA);
	else if ((*b)->index < (*a)->index && (*b)->index > tmp->index)
		ft_do_op(a, b, PA);
	else
		if (ft_find_next(*a, (*b)->index))
			ft_top_a(a, ft_find_next(*a, (*b)->index));
}
