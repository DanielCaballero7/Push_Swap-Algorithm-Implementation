/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:08:20 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/28 23:34:47 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
/*Swap the first node with the second node
	Stack = stack->next, stack->index*/
static void	swap(t_node *node, t_stack *stack)
{
	t_node	*tmp;

	if (!node || node->next == NULL)
		return ;
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
}

/*Rotate up 1 position all nodes
	1st node will be the last node
	change the pos
	change the last node*/
static void	rotate(t_node *node, t_stack *stack)
{
	t_node	*aux;

	aux = find_lst(node);
	aux->last = 0;
	node->last = 1;
	node->pos = stack->size;
	node = node->next;
	while (node->last == 0)
	{
		node->pos--;
		node = node->next;
	}
	ft_putstr_fd("r", 1);
	ft_putchar_fd(stack->id, 1);
}

/*Reverse rotate*/
static t_node	*r_rotate(t_node *node, t_stack *stack)
{
	t_node	aux;

	while (node->next->last == 0)
		node = node->next;
	node->last = 1;
	node->pos += 1;
	node->next->last = 0;
	node->next->pos = 0;
	node = node->next->next;
	while (node->last == 0)
	{
		node->pos++;
		node = node->next;
	}
	node = node->next;
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(stack->id, 1);
	return (node);
}

/*123 SORTED
  132 rr && s
  213 s
  231 rr
  312 r
  321 s && rr*/
static void	sort3(t_node *node, t_stack *stack)
{
	t_node	*aux;
	int		i;

	i = is_sorted(node);
	if (i == 0)
	{
		return ;
	}
	aux = node->next->next;
	if (node->index < node->next->index && node->index < aux->index)
		node = r_rotate(node, stack);
	else if (node->index > node->next->index && node->next->index > aux->index)
		swap(node, stack);
	if (node->index > node->next->index && node->index < aux->index)
		swap(node, stack);
	else if (node->index < node->next->index && node->index > aux->index)
		r_rotate(node, stack);
	else
		rotate(node, stack);
}

/*Push_swap algorithm*/
void	push_swap(t_node *stack_a, t_stack *stack_a_info)
{
	t_node	*stack_b;

	stack_b = NULL;
	if (!is_sorted(stack_a))
		return ;
	if (stack_a_info->size == 2)
		swap(stack_a, stack_a_info);
	else if (stack_a_info->size == 3)
		sort3(stack_a, stack_a_info);
	/*else
		sort(stack_a, stack_b);*/
}