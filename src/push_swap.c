/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:08:20 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/27 16:17:51 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*Swap the first node with the second node
	Stack = stack->next, stack->index*/
static void	swap(t_node *node)
{
	t_node	*tmp;

	if (!node || node->next == NULL)
		return;
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
}

/*Rotate up 1 position all nodes
	1st node will be the last node
	change the pos
	change the last node*/
static void	rotate (t_node *node)
{
	t_node	aux;
	aux = find_lst(node);
	aux->last = 0;
	node->last = 1
	node->pos = ; //size;
	node = node->next;
	while (node->last == 0)
		node->pos--;
	
}

/*Reverse rotate*/
static void	r_rotate(t_node *node)
{
	t_node	aux;
	while (node->next->last == 0)
		node = node->next;
	node->last = 1;
	node->next->last = 0;
	node->next->pos = 0;
	node = node->next->next
	while (node->last == 0)
		pos++;
}

/*123 SORTED
  132 rr && s
  213 s
  231 rr
  312 r
  321 s && rr*/
static void sort3(t_node *node)
{
	t_node	aux;

	if (is_sorted(node))
		return ;
	aux = node->next->next;
	if (node->index < node->next->index && node->index < aux->index)
		r_rotate(node);
	else if (node->index > node->next->index && node->next->index > aux->index)
		swap(node);
	if (node->index > node->next->index && node->index < aux->index)
		swap(node);
	else if (node->index < node->next->index && node->index > aux->index)
		r_rotate(node);
	else
		rotate(node);
}
/*Push_swap algorithm*/
static void	push_swap(t_node *stack_a)
{
	t_node	*stack_b;

	stack_b = NULL;
	if (stack_a->size == 2)
		swap(&stack_a);
	else if (stack_a.size == 3)
		sort_three(&stack_a);
	else
		sort(&stack_a, &stack_b);
}