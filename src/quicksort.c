/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:54:52 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/10 17:45:27 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_part_a(t_stack **a, t_stack **b)
{
	int	pivot;
	int	size;

	pivot = (ft_find_min(*a) + ft_find_max(*a) + 1) / 2;
	size = (ft_unsort(*a) / 2) - 1;
	while (ft_s_size(*b) < size && ft_s_size(*a) > 3)
	{
		if (!ft_find_fwd(*a, pivot))
			ft_do_op(a, b, PB);
		else
			ft_smart_rotate_a(a, b, pivot);
	}
}

void	ft_part_b(t_stack **a, t_stack **b)
{
	int	pivot;
	int	size;

	pivot = (ft_find_min(*b) + ft_find_max(*b) + 1) / 2;
	size = (ft_unsort(*b) / 2);
	ft_printf("pivot:%d fwd: %d, bwd: %d\n", pivot, ft_find_fwd_a(*b, pivot), ft_find_bwd_a(*b, pivot));
	ft_print_stack(*b);
	while (size)
	{
		if (!ft_find_fwd_a(*b, pivot))
		{
			ft_do_op(a, b, PA);
			size--;
		}
		else
			ft_smart_rotate_b(a, b, pivot);
	}
}
