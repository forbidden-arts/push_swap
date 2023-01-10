/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:54:52 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/10 19:31:32 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_part_a(t_stack **a, t_stack **b)
{
	int	pivot;
	int	size;

	pivot = (ft_find_min(*a) + ft_find_max(*a)) / 2 + 1;
	size = (ft_unsort(*a) / 2);
	while (ft_find_min(*a) < pivot && ft_s_size(*a) > 3)
	{
		if (!ft_find_fwd(*a, pivot))
			ft_do_op(a, b, PB);
		else
			ft_smart_rotate_a(a, b, pivot);
	}
	if (ft_s_size(*a) <= 3)
		ft_sort_mini_a(a, b);
}

void	ft_part_b(t_stack **a, t_stack **b)
{
	int	pivot;
	int	size;

	pivot = (ft_find_min(*b) + ft_find_max(*b)) / 2;
	size = (ft_unsort(*b) / 2);
	// ft_printf("pivot:%d fwd: %d, bwd: %d\n", pivot, ft_find_fwd_a(*b, pivot), ft_find_bwd_a(*b, pivot));
	while (ft_find_max(*b) > pivot && ft_s_size(*b) > 3)
	{
		ft_opportunity(a, b);
		if (!ft_find_fwd_a(*b, pivot))
			ft_do_op(a, b, PA);
		else
			ft_smart_rotate_b(a, b, pivot);
		// ft_print_stack(*b);
		ft_printf("max: %d pivot:%d fwd: %d, bwd: %d\n",ft_find_max(*b), pivot, ft_find_fwd_a(*b, pivot), ft_find_bwd_a(*b, pivot));
	}
}

void	ft_opportunity(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = ft_stack_last(*a);
	if ((*b)->index == 1 || (*b)->index == tmp->index + 1)
	{
		(*b)->sorted = 1;
		ft_do_op(a, b, PA);
		ft_do_op(a, b, RA);
	}
}
