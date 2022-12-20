/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:59:52 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/20 12:03:11 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_parse_to_stack(t_stack *a, char *str)
{
	int		i;
	long	num;
	char	**tmp;

	tmp = ft_split(str, ' ');
	i = 0;
	while (tmp[i])
	{
		num = ft_stk_atoi(tmp[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_tab_unwind(tmp);
			ft_exit_on_error(&a, NULL);
		}
		else
			ft_stack_add_tail(&a, ft_make_new_stack((int)num));
		i++;
	}
	ft_tab_unwind(tmp);
	return (a);
}

t_stack	*ft_make_new_stack(int i)
{
	t_stack	*new;

	new = malloc(sizeof(new));
	if (!new)
		return (NULL);
	new->value = i;
	new->next = NULL;
	return (new);
}

void	ft_stack_add_tail(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!*stack)
		*stack = new;
	else
	{
		temp = ft_stack_last(*stack);
		temp->next = new;
	}
}

void	ft_stack_add_head(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
}

t_stack	*ft_build_stack(t_stack *a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		a = ft_parse_to_stack(a, argv[i]);
		i++;
	}
	return (a);
}
