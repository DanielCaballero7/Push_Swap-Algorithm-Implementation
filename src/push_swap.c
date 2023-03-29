/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:08:20 by dcaballe          #+#    #+#             */
/*   Updated: 2023/03/21 19:01:30 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*sort3(t_node *node, t_stack *stack)
{
	t_node	*aux;
	int		i;

	i = is_sorted(node);
	if (i == 0)
	{
		return (node);
	}
	aux = node->next->next;
	if (node->index < node->next->index && node->index < aux->index)
		node = r_rotate(node, stack);
	if (node->index > node->next->index && node->next->index > aux->index)
		node = swap(node, stack);
	if (node->index > node->next->index
		&& node->index < node->next->next->index)
		node = swap(node, stack);
	else if (node->index < node->next->index
		&& node->index > node->next->next->index)
		node = r_rotate(node, stack);
	else
		node = rotate(node, stack);
	return (node);
}

t_node	*push_all(t_node *node_a, t_node *node_b,
					t_stack *stack_a_info, t_stack *stack_b_info)
{
	int		min;
	t_node	*aux;

	min = find_min_cost(node_b);
	while (min != node_b->pos)
	{
		if (node_b->pos < min && min < stack_b_info->size / 2)
			node_b = rotate(node_b, stack_b_info);
		else
			node_b = r_rotate(node_b, stack_b_info);
	}
	while (node_b->target != node_a->pos)
	{
		if (node_b->target >= stack_a_info->size / 2)
			node_a = r_rotate(node_a, stack_a_info);
		else
			node_a = rotate(node_a, stack_a_info);
	}
	return (push_make(node_a, node_b, stack_a_info));
}

void	sort_all(t_node *node_a, t_node *node_b,
	t_stack *stack_a_info, t_stack *stack_b_info)
{
	int		end;

	end = 0;
	update_stack(node_a, node_b, stack_a_info, stack_b_info);
	while (end == 0)
	{
		if (node_b->next != node_b)
		{
			node_b = push_all(node_a, node_b, stack_a_info, stack_b_info);
			node_a = (find_lst(node_a))->next;
			update_stack(node_a, node_b, stack_a_info, stack_b_info);
		}
		else
		{
			end = 1;
			push_all(node_a, node_b, stack_a_info, stack_b_info);
			node_a = (find_lst(node_a))->next;
		}
	}
	free(stack_b_info);
	rotate_free(node_a, stack_a_info);
}

void	sort(t_node *node_a, t_stack *stack_a_info)
{
	t_node	*node_b;
	t_node	*aux;
	t_stack	*stack_b_info;
	int		size;

	size = stack_a_info->size;
	stack_b_info = (t_stack *)malloc(sizeof(t_stack));
	stack_b_info->id = 'b';
	node_b = NULL;
	while (size-- > 3)
	{
		if (node_a->index < stack_a_info->size / 2)
		{
			aux = node_a->next;
			node_b = push(node_a, node_b, stack_b_info);
			node_a = aux;
			find_lst(node_a)->next = node_a;
		}
		else
			node_a = rotate(node_a, stack_a_info);
	}
	push_rest(node_a, node_b, stack_a_info, stack_b_info);
}

/*Push_swap algorithm*/
void	push_swap(t_node *stack_a, t_stack *stack_a_info)
{
	if (!is_sorted(stack_a))
		return ;
	if (stack_a_info->size == 2)
		swap(stack_a, stack_a_info);
	else if (stack_a_info->size == 3)
		sort3(stack_a, stack_a_info);
	else
		sort(stack_a, stack_a_info);
}
