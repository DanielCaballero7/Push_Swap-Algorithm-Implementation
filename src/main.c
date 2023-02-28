/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:58:17 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/28 19:22:13 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//proyecto push_swap 42
#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	long	*array;
	t_array	*index_array;
	t_stack	*stack_a;

	stack_a = malloc(sizeof(t_stack));
	if (argc == 1 || !stack_a)
	{
		ft_putstr_fd(ERROR_ARGS, 2);
		return (-1);
	}
	stack_a->size = parse_args(argc, argv, &array);
	if (stack_a->size == -1)
	{
		ft_putstr_fd(ERROR_ARGS, 2);
		return (-1);
	}
	if (check_duplicates(array, stack_a->size) == -1)
	{
		ft_putstr_fd(ERROR_ARGS, 2);
		return (-1);
	}
	index_array = organize_array(array, stack_a->size);
	if (!index_array)
		return (-1);
	return (0);
}
