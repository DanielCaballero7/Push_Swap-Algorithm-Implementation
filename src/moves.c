/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:52:46 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/27 14:52:47 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*make_stackb(t_node *node_a, t_node *node_b)
{
	node_b = node_a;
	node_b->next = NULL;
	node_b->last = 1;
	node_b->pos = 0;
	return (node_b);
}

t_node	*swap(t_node *node, t_stack *stack)
{
	t_node	*tmp;

	if (!node || node->next == NULL)
		return (node);
	tmp = node->next;
	if (tmp->last == 1)
	{
		tmp->last = 0;
		node->last = 1;
	}
	node->next = tmp->next;
	node->pos += 1;
	tmp->next = node;
	tmp->pos = 0;
	node = tmp;
	ft_putstr_fd("s", 1);
	ft_putchar_fd(stack->id, 1);
	ft_putchar_fd('\n', 1);
	tmp = find_lst(node);
	tmp->next = node;
	return (node);
}

t_node	*rotate(t_node *node, t_stack *stack)
{
	t_node	*aux;

	aux = find_lst(node);
	aux->last = 0;
	node->last = 1;
	node = node->next;
	ft_putstr_fd("r", 1);
	ft_putchar_fd(stack->id, 1);
	ft_putchar_fd('\n', 1);
	return (node);
}

t_node	*r_rotate(t_node *node, t_stack *stack)
{
	while (node->next->last == 0)
		node = node->next;
	node->last = 1;
	node->next->last = 0;
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(stack->id, 1);
	ft_putchar_fd('\n', 1);
	return (node->next);
}

t_node	*push(t_node *node_a, t_node *node_b, t_stack *stack_info)
{
	t_node	*aux;

	if (node_b == NULL)
		node_b = make_stackb(node_a, node_b);
	else
	{
		node_a->next = node_b;
		node_b = node_a;
		node_b->pos = 0;
		node_b->last = 0;
		aux = node_b;
		node_b = node_b->next;
		while (node_b->last == 0)
		{
			node_b->pos++;
			node_b = node_b->next;
		}
		node_b->pos++;
		node_b = aux;
	}
	ft_putchar_fd('p', 1);
	ft_putchar_fd(stack_info->id, 1);
	ft_putchar_fd('\n', 1);
	return (node_b);
}
