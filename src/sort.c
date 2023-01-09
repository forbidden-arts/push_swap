/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:00:22 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/09 15:14:47 by dpalmer          ###   ########.fr       */
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
		ft_sort_mini(a, b);
	else if (size <= 5)
		ft_sort_five(a, b, size);
	// ft_print_stack(*a);
	// ft_print_stack(*b);
}

void	ft_sort_mini(t_stack **a, t_stack **b)
{
	if (ft_stack_size(*a) == 2)
		ft_do_op(a, b, SA);
	while (!ft_is_sorted(*a))
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

void	ft_sort_five(t_stack **a, t_stack **b, int size)
{
	ft_partition(a, b);
	ft_sort_mini(a, b);
	if (ft_stack_size(*b) > 1 && (*b)->index < (*b)->next->index)
		ft_do_op(a, b, SB);
	ft_do_op_n(a, b, PA, size - 3);
}

/*  WORKS, BUT TOO MANY ACTIONS.
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
			ft_do_op_n(a, b, RRA, ft_stack_size(*a) - ft_find_last(*a, i));
		ft_do_op(a, b, PB);
	}
	ft_sort_mini(a);
	while ((*b))
		ft_push_back(a, b);
	while (!ft_is_sorted(*a))
	{
		if (ft_get_pos(*a, 1) + 1 > (ft_stack_size(*a) / 2)
			&& ft_stack_size(*a) < 6)
			ft_do_op(a, b, RA);
		else
			ft_do_op(a, b, RRA);
	}
}

void	ft_push_back(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = ft_stack_last(*a);
	if (ft_stack_size(*b) == 2 && (*b)->index > (*b)->next->index)
		ft_do_op(a, b, SB);
	if (ft_isbig(*a, (*b)->index))
	{
		while (!ft_is_sorted(*a))
			ft_do_op(a, b, RRA);
		ft_do_op(a, b, PA);
		ft_do_op(a, b, RA);
	}
	else if ((*b) && tmp->index < (*a)->index && tmp->index > (*b)->index)
		ft_do_op(a, b, RRA);
	else if ((*b)->index < (*a)->index)
		ft_do_op(a, b, PA);
	else if ((*a)->index < (*b)->index)
		ft_do_op(a, b, RA);
}
*/
