/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:48:44 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/10 22:00:00 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
