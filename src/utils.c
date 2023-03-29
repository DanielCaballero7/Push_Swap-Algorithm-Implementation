/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:08:49 by dcaballe          #+#    #+#             */
/*   Updated: 2023/03/28 22:08:49 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*push_make(t_node *node_a, t_node *node_b, t_stack *stack_a_info)
{
	t_node	*aux;

	if (node_b != node_b->next)
	{
		aux = node_b->next;
		node_a = push(node_b, node_a, stack_a_info);
		node_b = aux;
		node_b = find_lst(node_b);
		node_b->next = aux;
		node_b = aux;
		aux = node_a;
		node_a = find_lst(node_a);
		node_a->next = aux;
	}
	else
	{
		node_a = push(node_b, node_a, stack_a_info);
		node_a = find_lst(node_a);
		node_a->next = node_b;
		node_b = NULL;
	}
	return (node_b);
}

int	find_min_cost(t_node *node)
{
	t_node	*aux;
	int		last;

	last = 0;
	aux = node;
	while (last == 0)
	{
		if (node->nbr_moves < aux->nbr_moves)
			aux = node;
		node = node->next;
		if (node->last == 1)
			last = 1;
	}
	return (aux->pos);
}

void	find_cost(t_node *node, t_stack *stack_a, t_stack *stack_b)
{
	int	last;

	last = 0;
	while (last == 0)
	{
		if (node->target > stack_a->size / 2)
			node->nbr_moves = stack_a->size - node->target;
		else
			node->nbr_moves = node->target;
		if (node->pos > stack_b->size / 2)
			node->nbr_moves += stack_b->size - node->pos;
		else
			node->nbr_moves += node->pos;
		node = node->next;
		if (node->last == 1)
			last = 1;
	}
}

void	last_next(t_node *node)
{
	t_node	*aux;

	aux = find_lst(node);
	aux->next = node;
}

void	update_stack(t_node *node_a, t_node *node_b,
							t_stack *stack_a_info, t_stack *stack_b_info)
{
	node_a = (find_lst(node_a))->next;
	node_b = (find_lst(node_b))->next;
	set_position(node_a);
	set_position(node_b);
	find_target(node_a, node_b);
	stack_a_info->size = get_stack_size(node_a);
	stack_b_info->size = get_stack_size(node_b);
	find_cost(node_b, stack_a_info, stack_b_info);
}
