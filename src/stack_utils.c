/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:15:52 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/28 21:58:32 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*find_lst(t_node *node)
{
	while (node->last == 0)
		node = node->next;
	return (node);
}

int	is_sorted(t_node *node)
{
	if (node->last == 1)
		return (0);
	if (node->index < node->next->index)
		return (is_sorted(node->next));
	else
		return (1);
}

int	get_stack_size(t_node *node)
{
	while (node->last == 0)
		node = node->next;
	return (node->index);
}
