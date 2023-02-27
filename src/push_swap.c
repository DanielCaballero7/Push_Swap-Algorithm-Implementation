/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:08:20 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/26 14:22:20 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_a(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a->next;
	stack_a->next = tmp->next;
	tmp->next = stack_a;
	stack_a = tmp;
}

void rotate (t_stack *stack)
{
	
}
/*Push_swap algorithm*/

void	push_swap(t_stack stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (stack_a.size == 2)
		swap_a(&stack_a);
	else if (stack_a.size == 3)
		sort_three(&stack_a);
	else
		sort(&stack_a, &stack_b);
}