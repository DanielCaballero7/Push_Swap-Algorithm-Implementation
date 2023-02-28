/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:54:02 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/27 15:10:29 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*Transform t_array in t_stack_a*/

t_stack	*make_stack_a(t_array *array)
{
	t_stack	*stack_a;
	t_stack	*tmp;
	int		i;

	i = 0;
	stack_a = (t_stack *) malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->index = array->index[i];
	stack_a->pos = i;
	stack_a->next = NULL;
	tmp = stack_a;
	i++;
	while (i < array->size - 1)
	{
		stack_a->last = 0;
		stack_a->next = (t_stack *) malloc(sizeof(t_stack));
		if (!stack_a->next)
			return (NULL);
		stack_a = stack_a->next;
		stack_a->index = array->index[i];
		stack_a->pos = i;
		i++;
	}
	stack_a->last = 1;
	if (size > 1)
	{
		stack_a->next = tmp;
		stack_a = stack_a->next;
	}
	return (stack_a);
}

