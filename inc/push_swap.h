/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:00:41 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/28 23:35:48 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//push_swap.h
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERROR_ARGS "Error\n argumentos incorectos"
# define TRUE 1
# define FALSE 0
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



int				are_digits(char *str);
int				to_int_array(int argc, char **argv, int nums, long **array);
int				parse_args(int argc, char **argv, long **ptr);
t_node			*find_lst(t_node *node);
int				is_sorted(t_node *node);
int				get_stack_size(t_node *node);
int				*fill_index(int *index, int nums);
int				check_duplicates(long *array, int nums);
t_array			*organize_array(long *array, int size);
int				sort_array(t_array *index_array);
t_node			*make_stack_a(t_array *array);
t_node			*make_node(t_array *array, int i);
t_node			*find_lst(t_node *node);
int				is_sorted(t_node *node);
int				get_stack_size(t_node *node);
void			push_swap(t_node *stack_a, t_stack *stack_a_info);
static void		sort3(t_node *node, t_stack *stack);
static t_node	*r_rotate(t_node *node, t_stack *stack);
static void		rotate(t_node *node, t_stack *stack);
static void		swap(t_node *node, t_stack *stack);

#endif