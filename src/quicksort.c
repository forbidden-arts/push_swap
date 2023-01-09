/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:54:52 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/09 16:45:02 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_part_init(t_stack **a, t_stack **b)
{
	int	pivot;

	pivot = ft_stack_avg(*a);
	// ft_printf("pivot: %d\n", pivot);
	// ft_print_stack(*a);
	while (ft_stack_size(*b) < ft_size_unsort(*a) - 1 && ft_stack_size (*a) > 3)
	{
		if (ft_smart_rotate(a, pivot) == 1)
			ft_do_op(a, b, RA);
		else if (ft_smart_rotate(a, pivot) == -1)
			ft_do_op(a, b, RRA);
		else if (ft_smart_rotate(a, pivot) == 0)
			ft_do_op(a, b, PB);
	}
}
