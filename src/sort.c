/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:00:22 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/02 12:24:24 by dpalmer          ###   ########.fr       */
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
		ft_bucketize(*a, 2);
		ft_sort_stacks(a, b);
	}
}

void	ft_sort_mini(t_stack **a)
{
	if (ft_stack_size(*a) == 2)
		ft_do_op(a, NULL, SA);
	while (!ft_is_sorted(*a))
	{
		if ((*a)->index > (*a)->next->index && (*a)->index
			> (*a)->next->next->index)
			ft_do_op(a, NULL, RA);
		else if ((*a)->index > (*a)->next->next->index)
			ft_do_op(a, NULL, RRA);
		else
			ft_do_op(a, NULL, SA);
	}
}

void	ft_sort_stacks(t_stack **a, t_stack **b)
{
	int		i;

	i = 1;
	while (!ft_is_sorted(*a) && ft_stack_size(*a) > 3)
	{
		if (!ft_find_last(*a, i))
			i++;
		if (ft_find_next(*a, i) + 1 < ft_stack_size(*a) - ft_find_last(*a, i))
			ft_do_op_n(a, b, RA, ft_find_next(*a, i) - 1);
		else
			ft_do_op_n(a, b, RRA, ft_stack_size(*a) - ft_find_last(*a, i) + 1);
		ft_do_op(a, b, PB);
	}
	ft_sort_mini(a);
	ft_print_stack(*a);
	ft_print_stack(*b);
	while ((*b))
		ft_push_back(a, b);
	ft_print_stack(*a);
	ft_print_stack(*b);
}

void	ft_push_back(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (ft_isbig(*a, (*b)->index))
	{
		ft_do_op(a, b, PA);
		ft_do_op(a, b, RA);
	}
	else
	{
		while ((*a)->index < (*b)->index)
		{
			ft_do_op(a, b, RA);
			i++;
		}
		ft_do_op(a, b, PA);
	}
	ft_do_op_n(a, b, RRA, i);
}

/*
LOGIC: if B->index is greater than anything in A, push it over and RA
Otherwise: rotate A until b > index but < next.index. PA, rotate back.

else if ((*a)->index > (*a)->next->index && (*b)->index < (*b)->next->index)
ft_do_op(a, b, SS);
else if ((*b)->index < (*b)->next->index)
ft_do_op(a, b, SB);
*/
