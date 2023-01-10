/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:54:52 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/10 22:00:46 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_part_a(t_stack **a, t_stack **b)
{
	int	pivot;

	pivot = (ft_find_min(*a) + ft_find_max(*a)) / 2 + 1;
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

	pivot = (ft_find_min(*b) + ft_find_max(*b)) / 2;
	while (ft_find_max(*b) > pivot && ft_s_size(*b) > 3)
	{
		ft_opportunity(a, b);
		if (!ft_find_fwd_a(*b, pivot))
			ft_do_op(a, b, PA);
		else
			ft_smart_rotate_b(a, b, pivot);
	}
	if (ft_s_size(*b) <= 3)
	{
		ft_sort_mini_b(a, b);
		ft_do_op_n(a, b, PA, ft_s_size(*b));	
	}
}

/* TODO: QUICKSORT!

*/