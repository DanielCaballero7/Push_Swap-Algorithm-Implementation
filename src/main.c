/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:58:17 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/26 13:52:56 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//proyecto push_swap 42
#include "../inc/push_swap.h"

/**/

int	check_duplicates(long *array, int nums)
{
	int		i;
	int		j;

	i = 0;
	while (i < nums)
	{
		j = i + 1;
		while (j < nums)
		{
			if (array[i] == array[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*fill_index(int *index, int nums)
{
	int	i;

	i = 1;
	while (i <= nums)
	{
		index[i - 1] = nums;
		i++;
	}
	return (index);
}

int	sort_array(t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack_a->size)
	{
		j = 0;
		while (j < stack_a->size)
		{
			if ((stack_a->array[i] < stack_a->array[j]) && (i != j))
				stack_a->index[i]--;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < stack_a->size)
	{
		ft_putnbr_fd(stack_a->index[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	return (0);
}

t_stack	*organize_array(long *all_nums, int nums)
{
	t_array	*array;

	array = malloc(sizeof(t_array));
	if (!array)
		return (NULL);
	array->array = all_nums;
	array->index = malloc(sizeof(int) * nums);
	if (!array->index)
		return (-1);
	array->index = fill_index(array->index, nums);
	sort_array(array);
	return (array);
}

int	push_swap(t_stack *stack_a)
{
}

int	main(int argc, char **argv)
{
	long	*array;
	int		nums;
	t_array	*all_nums;

	if (argc == 1)
	{
		ft_putstr_fd(ERROR_ARGS, 2);
		return (-1);
	}
	nums = parse_args(argc, argv, &array);
	if (nums == -1)
	{
		ft_putstr_fd(ERROR_ARGS, 2);
		return (-1);
	}
	if (check_duplicates(array, nums) == -1)
	{
		ft_putstr_fd(ERROR_ARGS, 2);
		return (-1);
	}
	all_nums = organize_array(array, nums);
	free(array);
	return (0);
}
