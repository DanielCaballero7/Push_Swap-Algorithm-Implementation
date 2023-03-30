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

t_node	*push_all(t_node *na, t_node *nb,
					t_stack *ainfo, t_stack *binfo)
{
	int		min;
	t_node	*aux;
	t_ps	*ps;

	ps = init_ps(na, nb, ainfo, binfo);
	aux = nb;
	min = find_min_cost(nb);
	while (min != aux->pos)
		aux = aux->next;
	ps = chooserotate(ps, aux);
	while (ps->b->target != ps->a->pos)
	{
		if (ps->b->target >= ps->ainfo->size / 2)
			ps->a = r_rotate(ps->a, ps->ainfo);
		else
			ps->a = rotate(ps->a, ps->ainfo);
	}
	na = ps->a;
	nb = ps->b;
	ainfo = ps->ainfo;
	free (ps);
	return (push_make(na, nb, ainfo));
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
	while (size-- > 5)
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

void	push_swap(t_node *stack_a, t_stack *stack_a_info)
{
	t_node	*aux;

	if (!is_sorted(stack_a))
		;
	else if (stack_a_info->size == 2)
		swap(stack_a, stack_a_info);
	else if (stack_a_info->size == 3)
		sort3(stack_a, stack_a_info);
	else
	{
		sort(stack_a, stack_a_info);
		return ;
	}
	free(stack_a_info);
	while (stack_a->last == 0)
	{
		aux = stack_a->next;
		free(stack_a);
		stack_a = aux;
	}
	free(stack_a);
}
