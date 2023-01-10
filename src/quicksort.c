/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:54:52 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/10 15:31:00 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_part_a(t_stack **a, t_stack **b)
{
	int	pivot;

	pivot = (ft_find_min(*a) + ft_find_max(*a) + 1) / 2;
	ft_printf("pivot: %d\n", pivot);
	ft_print_stack(*a);
	while (ft_s_size(*b) < ft_unsort(*a) - 1 && ft_s_size(*a) > 3)
	{
		if (!ft_find_fwd(*a, pivot))
			ft_do_op(a, b, PB);
		else
			ft_smart_rotate_a(a, pivot);
	}
}
// void	ft_part_init(t_stack **a, t_stack **b)
// {
// 	int	pivot;

// 	pivot = ft_s_size(*a);
// 	while (ft_s_size(*b) < ft_unsort(*a) - 1 && ft_s_size (*a) > 3)
// 	{
// 		if (ft_smart_rotate_a(a, pivot) == 1)
// 			ft_do_op(a, b, RA);
// 		else if (ft_smart_rotate_a(a, pivot) == -1)
// 			ft_do_op(a, b, RRA);
// 		else if (ft_smart_rotate_a(a, pivot) == 0)
// 			ft_do_op(a, b, PB);
// 	}
// }
