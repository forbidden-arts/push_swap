/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:22:54 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/27 13:56:37 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

typedef struct s_stack
{
	int				value;
	int				bucket;
	int				index;
	struct s_stack	*next;
}					t_stack;

/*		Stack building			*/
void	ft_stack_add_head(t_stack **stack, t_stack *new);
void	ft_stack_add_tail(t_stack **stack, t_stack *new);
t_stack	*ft_parse_to_stack(t_stack *a, char *str);
t_stack	*ft_make_new_stack(int i);
t_stack	*ft_build_stack(t_stack *a, char **argv);

/*		General Utilities		*/
int		ft_is_sorted(t_stack *a);
long	ft_stk_atoi(const char *str);

/*		Error Related			*/
void	ft_tab_unwind(char **tab);
void	ft_exit_on_error(t_stack **a, t_stack **b);
void	ft_stk_chk_valid(char **argv);
void	ft_free_stack(t_stack **stack);
void	ft_chk_dup_stack(t_stack *a);

/*		Stack Utilities			*/
void	ft_rotate_stack(t_stack **stack, int dir);
void	ft_push_stack(t_stack **dst, t_stack **src);
void	ft_stack_swap(t_stack **stack);
t_stack	*ft_stack_last(t_stack *stack);
t_stack	*ft_stack_sec_last(t_stack *stack);

/*		Stack Stats				*/
int		ft_stack_size(t_stack *stack);
void	assign_index(t_stack *stack);

/*		Rotation				*/
void	ft_rotate_a(t_stack **stack, int dir);
void	ft_rotate_b(t_stack **stack, int dir);
void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b, int dir);

/*		Stack Actions			*/
void	ft_swap_a(t_stack **stack);
void	ft_swap_b(t_stack **stack);
void	ft_swap_both(t_stack **stack_a, t_stack **stack_b);
void	ft_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);

#endif
