/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:15:52 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/27 15:23:05 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*find_lst(t_node *node)
{
	while (node->last == 0)
		node = node->next;
	return (*node);
}

int	is_sorted(t_node *node)
{
	if (stack->last == 1)
		return (0);
	if (stack->index < stack->next->index )
		return (is_sorted(stack->next));
	else
		return (1);
}

int	get_stack_size(t_node *node)
{
	while (node->last == 0)
		node = node->next;
	return (node->index);
}
