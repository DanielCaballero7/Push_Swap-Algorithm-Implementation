/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:00:41 by dcaballe          #+#    #+#             */
/*   Updated: 2023/03/21 21:24:27 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_array
{
	long	*array;
	int		*index;
	int		size;
}	t_array;

typedef struct s_node
{
	int				index;
	int				pos;
	int				nbr_moves;
	int				target;
	int				last;
	struct s_node	*next;
}	t_node;

typedef struct stack
{
	int				size;
	t_node			*top;
	t_node			*bottom;
	char			id;
}	t_stack;

typedef struct s_ps
{
	t_node	*a;
	t_node	*b;
	t_stack	*ainfo;
	t_stack	*binfo;
}	t_ps;

int				are_digits(const char *str);
int				to_int_array(int argc, char **argv, int nums, long **array);
void			ft_error(int fd);
void			array_error(long *array, t_ps *ps);
void			ps_error(t_ps *ps);
t_ps			*init_push_swap(int argc);
int				parse_args(int argc, char **argv, long **array);
t_node			*make_stackb(t_node *node_a, t_node *node_b);
void			rotate_free(t_node *node_a, t_stack *stack_a_info);
t_node			*find_lst(t_node *node);
t_node			*push_make(t_node *node_a, t_node *node_b,
					t_stack *stack_a_info);
int				is_sorted(t_node *node);
int				find_min_cost(t_node *node);
void			update_stack(t_node *node_a, t_node *node_b,
					t_stack *stack_a_info, t_stack *stack_b_info);
int				get_stack_size(t_node *node);
void			find_mintgt(t_node *node_a, t_node *node_b, const t_node *fst);
int				*fill_index(int *index, int nums);
int				check_duplicates(const long *array, int nums);
t_array			*organize_array(long *array, int size);
int				sort_array(t_array *index_array);
t_node			*make_stack_a(t_array *array);
t_node			*make_node(t_array *array, int i);
t_node			*find_lst(t_node *node);
int				is_sorted(t_node *node);
int				get_stack_size(t_node *node);
void			push_swap(t_node *stack_a, t_stack *stack_a_info);
void			rrr(t_ps *ps);
void			rr(t_ps *ps);
t_ps			*init_ps(t_node *a, t_node *b, t_stack *ainfo, t_stack *binfo);
void			push_rest(t_node *node_a, t_node *node_b, t_stack *stack_a_info,
					t_stack *stack_b_info);
void			set_position(t_node *node);
void			set_target(t_node *node_a, t_node *node_b);
t_ps			*chooserotate(t_ps *ps, t_node *aux);
void			find_target(t_node *node_a, t_node *node_b);
void			last_next(t_node *node);
void			find_cost(t_node *node, t_stack *stack_a, t_stack *stack_b);
t_node			*sort3(t_node *node, t_stack *stack);
t_node			*push(t_node *node_a, t_node *node_b, t_stack *stack_info);
t_node			*r_rotate(t_node *node, t_stack *stack);
t_node			*rotate(t_node *node, t_stack *stack);
t_node			*swap(t_node *node, t_stack *stack);
void			sort_all(t_node *node_a, t_node *node_b,
					t_stack *stack_a_info, t_stack *stack_b_info);
t_node			*push_all(t_node *node_a, t_node *node_b,
					t_stack *stack_a_info, t_stack *stack_b_info);

#endif