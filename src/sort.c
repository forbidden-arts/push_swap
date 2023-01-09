/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:00:22 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/02 21:21:20 by dpalmer          ###   ########.fr       */
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
	// else
	// {
	// 	ft_bucketize(*a, 2);
	// 	ft_sort_stacks(a, b);
	// }
	ft_print_stack(*b);
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

void	ft_smart_rotate_a(t_stack **a, int i)
{
	while ((*a)->index > i)
	{
		if (ft_find_fwd(*a, i) <= ft_find_bwd(*a, i))
			ft_do_op(a, NULL, RA);
		else
			ft_do_op(a, NULL, RRA);
	}
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