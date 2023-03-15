/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:58:52 by dcaballe          #+#    #+#             */
/*   Updated: 2023/03/10 15:26:21 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_position(t_node *node)
{
	int	i;

	i = 0;
	while (node->last == 0)
	{
		node->pos = i;
		i++;
		node = node->next;
	}
	node->pos = i;
	node = node->next;
}

static void	set_target(t_node *node_a, t_node *node_b)
{
	int	aux;
	int	aux2;

	aux = node_a->index - node_b->index;
	if (aux < 0)
		aux = aux * -1;
	while (node_a->last == 0)
	{
		aux2 = node_a->index - node_b->index;
		if (aux2 < 0)
			aux2 = aux2 * -1;
		if (node_a->index > node_b->index && aux2 <= aux)
		{
			node_b->target = node_a->pos;
			aux = aux2;
		}
		node_a = node_a->next;
	}
	aux2 = node_a->index - node_b->index;
	if (aux2 < 0)
		aux2 = aux2 * -1;
	if (node_a->index > node_b->index && aux2 <= aux)
	{
		node_b->target = node_a->pos;
		aux = aux2;
	}
	node_a = node_a->next;
}

void	find_target(t_node *node_a, t_node *node_b)
{
	while (node_b->last == 0)
	{
		node_b->target = 0;
		set_target(node_a, node_b);
		node_b = node_b->next;
	}
	node_b->target = 0;
	set_target(node_a, node_b);
	node_b = node_b->next;
}