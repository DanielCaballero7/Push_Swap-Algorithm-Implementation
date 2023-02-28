/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:00:41 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/27 15:23:35 by dcaballe         ###   ########.fr       */
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

int	are_digits(char *str);
int	to_int_array(int argc, char **argv, int nums, long **array);
int	parse_args(int argc, char **argv, long **ptr);
t_node	*find_lst(t_node *node);
int	is_sorted(t_node *node);
int	get_stack_size(t_node *node);

typedef struct s_array
{
	int	*array;
	int	*index;
	int	size;
}	t_array;

typedef struct s_node
{
	int				index;
	int				pos;
	int				nbr_moves;
	int				last;
	struct s_stack	*next;
}	t_node;

typedef struct stack
{
	int				size;
	t_node			*top;
	t_node			*bottom;
}	t_stack;


#endif