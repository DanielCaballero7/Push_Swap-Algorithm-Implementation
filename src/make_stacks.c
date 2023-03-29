/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:54:02 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/28 22:12:05 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*Transform t_array in t_node_a*/

t_node	*make_node(t_array *array, int i)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->index = array->index[i];
	node->pos = i;
	return (node);
}

t_node	*make_stack_a(t_array *array)
{
	t_node	*node_a;
	t_node	*tmp;
	int		i;

	i = 0;
	node_a = make_node(array, i);
	node_a->next = NULL;
	tmp = node_a;
	i++;
	while (i < array->size)
	{
		node_a->last = 0;
		node_a->next = make_node(array, i);
		node_a = node_a->next;
		i++;
	}
	node_a->last = 1;
	if (array->size > 1)
	{
		node_a->next = tmp;
		node_a = node_a->next;
	}
	return (node_a);
}
