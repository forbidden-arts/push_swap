/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:10:20 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/02 21:43:13 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp != NULL)
	{
		ft_printf("num: %d idx: %d bkt:%d max:%d\n",
			tmp->value, tmp->index, tmp->bucket);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	ft_stk_chk_valid(argv);
	a = ft_build_stack(a, argv);
	ft_chk_dup_stack(a);
	ft_sort_control(&a, &b);
	ft_printf("%d, %d\n", ft_find_fwd(a, 3), ft_find_bwd(a, 3));
	// ft_printf("%d\n", ft_stack_avg(a));
	// ft_printf("%d\n", ft_find_max(b));
	// ft_printf("%d\n", ft_find_min(a));
	// ft_printf("%d\n", ft_find_min(b));
	// a->sorted = 1;
	// a->next->sorted = 1;
	ft_printf("%d\n", ft_stack_avg(a));
	return (0);
}


//TODO: FIX AVERAGE, ADJUST FOR UNSORTED.