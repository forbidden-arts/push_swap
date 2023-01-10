/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:22:54 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/10 21:50:34 by dpalmer          ###   ########.fr       */
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

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef struct s_stack
{
	int				value;
	int				index;
	int				sorted;
	int				pushed;
	char			*loc;
	struct s_stack	*next;
}					t_stack;

/*		Stack building			*/
void	ft_stack_add_head(t_stack **stack, t_stack *new);
void	ft_stack_add_tail(t_stack **stack, t_stack *new);
t_stack	*ft_parse_to_stack(t_stack *a, char *str);
t_stack	*ft_make_new_stack(int i);
t_stack	*ft_build_stack(t_stack *a, char **argv);

/*		General Utilities		*/
int		ft_get_pos(t_stack *stack, int n);
int		ft_is_sorted(t_stack *a, int dir);
long	ft_stk_atoi(const char *str);
int		ft_s_size(t_stack *stack);
int		ft_unsort(t_stack *stack);

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
void	ft_assign_index(t_stack *stack);
int		ft_find_max(t_stack *stack);
int		ft_find_min(t_stack *stack);
// int		ft_stack_avg(t_stack *stack);

/*		Stack Actions			*/
void	ft_do_op(t_stack **a, t_stack **b, char *op);
void	ft_do_op_n(t_stack **a, t_stack **b, char *op, int n);
int		ft_match(char *a, char *b);

/*		Sort					*/
void	ft_sort_control(t_stack **a, t_stack **b);
void	ft_sort_mini_a(t_stack **a, t_stack **b);
void	ft_sort_mini_b(t_stack **a, t_stack **b);
void	ft_sort_small(t_stack **a, t_stack **b);

/*		Rotate					*/
void	ft_smart_rotate_a(t_stack **a, t_stack **b, int i);
void	ft_smart_rotate_b(t_stack **a, t_stack **b, int i);
void	ft_top_a(t_stack **stack, int i);

/*		Math Ops				*/
int		ft_find_fwd(t_stack *stack, int b);
int		ft_find_bwd(t_stack *stack, int b);
int		ft_find_next(t_stack *stack, int b);
int		ft_find_fwd_a(t_stack *stack, int b);
int		ft_find_bwd_a(t_stack *stack, int b);

/*		Quicksort				*/
void	ft_part_a(t_stack **a, t_stack **b);
void	ft_part_b(t_stack **a, t_stack **b);
void	ft_opportunity(t_stack **a, t_stack **b);

/*		Shortcuts				*/


/*		Misc					*/
void	ft_print_stack(t_stack *a);

#endif
