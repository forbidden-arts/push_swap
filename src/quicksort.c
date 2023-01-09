/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:54:52 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/09 18:21:36 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_part_init(t_stack **a, t_stack **b)
{
	int	pivot;

	pivot = ft_stack_avg(*a);
	while (ft_s_size(*b) < ft_unsort(*a) - 1 && ft_s_size (*a) > 3)
	{
		if (ft_smart_rotate(a, pivot) == 1)
			ft_do_op(a, b, RA);
		else if (ft_smart_rotate(a, pivot) == -1)
			ft_do_op(a, b, RRA);
		else if (ft_smart_rotate(a, pivot) == 0)
			ft_do_op(a, b, PB);
	}
}
