/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:54:52 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/10 18:23:08 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_part_a(t_stack **a, t_stack **b)
{
	int	pivot;
	int	size;

	pivot = (ft_find_min(*a) + ft_find_max(*a) + 1) / 2;
	size = (ft_unsort(*a) / 2);
	ft_printf("pivot:%d fwd: %d, bwd: %d\n", pivot, ft_find_fwd_a(*a, pivot), ft_find_bwd_a(*a, pivot));
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
	while (size && ft_s_size(*b) > 3)
	{
		if (ft_opportunity(a, b))
		{
			size--;
			continue ;
		}
		if (!ft_find_fwd_a(*b, pivot))
		{
			ft_do_op(a, b, PA);
			size--;
		}
		else
			ft_smart_rotate_b(a, b, pivot);
	}
}

int	ft_opportunity(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = ft_stack_last(*a);
	if ((*b)->index == 1 || (*b)->index == tmp->index + 1)
	{
		(*b)->sorted = 1;
		ft_do_op(a, b, PA);
		ft_do_op(a, b, RA);
		return (1);
	}
	return (0);
}
