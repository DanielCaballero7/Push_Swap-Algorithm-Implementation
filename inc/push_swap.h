/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:00:41 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/26 13:56:16 by dcaballe         ###   ########.fr       */
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

typedef struct s_array
{
	int	*array;
	int	*index;
	int	size;
}	t_array;

typedef struct s_stack
{
	int				index;
	int				pos;
	int				nbr_moves;
	struct s_stack	*next;
}	t_stack;

#endif