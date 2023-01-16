/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:48:44 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/16 17:10:49 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_opportunity_b(t_stack **a, t_stack **b)
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

void	ft_q_init(t_stack **a, t_stack **b)
{
	int	pivot;

	ft_print_stack(*a);
	if (ft_s_size(*b) || (*a)->pushed)
		return ;
	pivot = ((ft_find_min(*a) + ft_find_max(*a)) / 2 + 1 -(ft_s_size(*a) % 2));
	while (ft_find_min(*a) < pivot)
	{
		if (!ft_find_fwd(*a, pivot))
			ft_do_op(a, b, PB);
		else
			ft_smart_rotate_a(a, b, pivot);
	}
}
