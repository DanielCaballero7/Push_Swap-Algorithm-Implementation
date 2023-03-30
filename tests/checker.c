/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:26:46 by dcaballe          #+#    #+#             */
/*   Updated: 2023/03/21 21:26:46 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	long	*array;
	t_array	*index_array;
	t_stack	*stack_a;
	t_node	*node_a;

	if (argc == 1)
		ft_error(NO_ARGS, 2, 0);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		ft_error(ALLOCATION_FAIL, 2, 1);
	stack_a->size = parse_args(argc, argv, &array);
	if (stack_a->size == -1)
		ft_error(ERROR_ARGS, 2, 1);
	if (check_duplicates(array, stack_a->size) == -1)
		ft_error(ERROR_ARGS, 2, 1);
	index_array = organize_array(array, stack_a->size);
	if (!index_array)
		ft_error(ALLOCATION_FAIL, 2, 1);
	node_a = make_stack_a(index_array);
	free(index_array->array);
	free(index_array->index);
	free(index_array);
	stack_a->id = 'a';
	push_swap(node_a, stack_a);
	return (0);
}
