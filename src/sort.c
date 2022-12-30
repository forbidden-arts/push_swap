/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:00:22 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/30 21:37:22 by dpalmer          ###   ########.fr       */
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
		ft_sort_stacks(a, b);
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

void	ft_sort_stacks(t_stack **a, t_stack **b)
{
	int		index;
	int		pos;

	index = 1;
	while (!ft_is_sorted(*a) && ft_stack_size(*a) > 3)
	{
		pos = ft_get_pos(*a, index);
		ft_push_index(a, b, pos, ft_stack_size(*a));
		index++;
	}
	ft_sort_mini(a);
	while (*b)
	{
		ft_do_op(a, b, PA);
	}
}

void	ft_push_index(t_stack **a, t_stack **b, int pos, int size)
{
	if (pos <= size / 2)
		ft_do_op_n(a, b, RA, pos - 1);
	else
		ft_do_op_n(a, b, RRA, size - pos + 1);
	ft_do_op(a, b, PB);
}
