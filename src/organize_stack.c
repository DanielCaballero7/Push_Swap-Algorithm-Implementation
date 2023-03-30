/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:23:41 by dcaballe          #+#    #+#             */
/*   Updated: 2023/03/29 12:23:41 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_rest(t_node *node_a, t_node *node_b, t_stack *stack_a_info,
		t_stack *stack_b_info)
{
	int		size;
	t_node	*aux;

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

void	rotate_free(t_node *node_a, t_stack *stack_a_info)
{
	int		min;
	t_node	*aux;

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
	free(node_a);
	free(stack_a_info);
}

void	rr(t_ps *ps)
{
	find_lst(ps->a)->last = 0;
	ps->a->last = 1;
	find_lst(ps->b)->last = 0;
	ps->b->last = 1;
	ft_putstr_fd("rr\n", 1);
	ps->a = ps->a->next;
	ps->b = ps->b->next;
}

void	rrr(t_ps *ps)
{
	while (ps->a->next->last != 1)
		ps->a = ps->a->next;
	while (ps->b->next->last != 1)
		ps->b = ps->b->next;
	ps->a->last = 1;
	ps->a->next->last = 0;
	ps->b->last = 1;
	ps->b->next->last = 0;
	ft_putstr_fd("rrr\n", 1);
	ps->a = ps->a->next;
	ps->b = ps->b->next;
}

t_ps	*init_ps(t_node *a, t_node *b, t_stack *ainfo, t_stack *binfo)
{
	t_ps	*ps;

	ps = malloc(sizeof(t_ps));
	if (!ps)
		return (NULL);
	ps->a = a;
	ps->b = b;
	ps->ainfo = ainfo;
	ps->binfo = binfo;
	return (ps);
}
