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

static void	find_cost(t_node *node, t_stack *stack_a, t_stack *stack_b)
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

static void	last_next(t_node *node)
{
	t_node	*aux;

	aux = find_lst(node);
	aux->next = node;
}

/*Swap the first node with the second node
	Stack = stack->next, stack->index*/
static t_node	*swap(t_node *node, t_stack *stack)
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

/*Rotate up 1 position all nodes
	1st node will be the last node
	change the pos
	change the last node*/
static t_node	*rotate(t_node *node, t_stack *stack)
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

/*Reverse rotate*/
static t_node	*r_rotate(t_node *node, t_stack *stack)
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

/*123 SORTED
  132 rr && s
  213 s
  231 rr
  312 r
  321 s && rr*/
static t_node	*sort3(t_node *node, t_stack *stack)
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
	if (node->index > node->next->index && node->index < node->next->next->index)
		node = swap(node, stack);
	else if (node->index < node->next->index && node->index > node->next->next->index)
		node = r_rotate(node, stack);
	else
		node = rotate(node, stack);
	return (node);
}

static t_node	*push(t_node *node_a, t_node *node_b, t_stack *stack_info)
{
	t_node	*aux;

	if (node_b == NULL)
	{
		node_b = node_a;
		node_b->next = NULL;
		node_b->last = 1;
		node_b->pos = 0;
	}
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

static void	update_stack(t_node *node_a, t_node *node_b,
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

static t_node	*push_all(t_node *node_a, t_node *node_b,
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
		node_a = node_b;
		node_b = NULL;
	}
	return (node_b);
}

static void	sort_all(t_node *node_a, t_node *node_b, t_stack *stack_a_info, t_stack *stack_b_info)
{
	int		min;
	int		end;
	t_node	*aux;

	end = 0;
	update_stack(node_a, node_b, stack_a_info, stack_b_info);
	while (end == 0)
	{
		if(node_b->next != node_b)
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
	while (node_a->index != 0)
	{
		min = get_stack_size(node_a) / 2;
		if (node_a->index > min)
			node_a = rotate(node_a, stack_a_info);
		else
			node_a = r_rotate(node_a, stack_a_info);
	}
	while (node_a->last == 0)
	{
		aux = node_a->next;
		free(node_a);
		node_a = aux;
	}
}

static void	sort(t_node *node_a, t_stack *stack_a_info)
{
	t_node	*node_b;
	t_node	*aux;
	t_stack	*stack_b_info;
	int		size;
	int		i;

	node_b = NULL;
	size = stack_a_info->size;
	stack_b_info = (t_stack *)malloc(sizeof(t_stack));
	stack_b_info->id = 'b';
	i = 0;
	while (size > 3)
	{
		if (node_a->index < stack_a_info->size / 2)
		{
			aux = node_a->next;
			node_b = push(node_a, node_b, stack_b_info);
			node_a = aux;
			aux = find_lst(node_a);
			aux->next = node_a;
			i++;
		}
		else
			if (stack_a_info->size > 1 && i <= (stack_a_info->size / 2))
				node_a = rotate(node_a, stack_a_info);
		size--;
	}
	stack_a_info->size = get_stack_size(node_a);
	size = stack_a_info->size;
	while (size > 3)
	{
		aux = node_a->next;
		node_b = push(node_a, node_b, stack_b_info);
		node_a = aux;
		aux = find_lst(node_a);
		aux->next = node_a;
		size--;
	}
	last_next(node_b);
	stack_a_info->size = 3;
	node_a = sort3(node_a, stack_a_info);
	sort_all(node_a, node_b, stack_a_info, stack_b_info);
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
