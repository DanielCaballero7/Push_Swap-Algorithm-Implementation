/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:58:52 by dcaballe          #+#    #+#             */
/*   Updated: 2023/03/20 19:23:32 by dcaballe         ###   ########.fr       */
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
}

void	find_mintgt(t_node *node_a, t_node *node_b, const t_node *fst)
{
	int	start;
	int	aux;

	aux = 32767;
	start = 0;
	while (node_a != fst || start == 0)
	{
		start = 1;
		if (aux > node_a->index)
		{
			aux = node_a->index;
			node_b->target = node_a->pos;
		}
		node_a = node_a->next;
	}
}

void	set_target(t_node *node_a, t_node *node_b)
{
	const t_node	*first;
	int				start;
	int				aux;

	start = 0;
	first = node_a;
	aux = 32767;
	while (node_a != first || start == 0)
	{
		start = 1;
		if (node_b->index < node_a->index && aux > node_a->index)
		{
			aux = node_a->index;
			node_b->target = node_a->pos;
		}
		node_a = node_a->next;
	}
	if (aux == 32767)
		find_mintgt(node_a, node_b, first);
}

void	find_target(t_node *node_a, t_node *node_b)
{
	const t_node	*first;
	int				start;

	start = 0;
	first = node_b;
	while (node_b != first || start == 0)
	{
		start = 1;
		node_b->target = 0;
		set_target(node_a, node_b);
		node_b = node_b->next;
	}
}

t_ps	*chooserotate(t_ps *ps, t_node *aux)
{
	while (aux->pos != ps->b->pos)
	{
		if (aux->target != ps->a->pos)
		{
			if (aux->pos < ps->binfo->size / 2
				&& aux->target < ps->ainfo->size / 2)
				rr(ps);
			else if (aux->pos > ps->binfo->size / 2
				&& aux->target > ps->ainfo->size / 2)
				rrr(ps);
			else if (aux->pos < ps->binfo->size / 2)
				ps->b = rotate(ps->b, ps->binfo);
			else
				ps->b = r_rotate(ps->b, ps->binfo);
		}
		else
		{
			if (aux->pos < ps->binfo->size / 2)
				ps->b = rotate(ps->b, ps->binfo);
			else
				ps->b = r_rotate(ps->b, ps->binfo);
		}
	}
	return (ps);
}
