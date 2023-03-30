/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:58:17 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/28 19:22:13 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_ps	*init_push_swap(int argc)
{
	t_ps	*ps;

	if (argc == 1)
		exit(1);
	ps = (t_ps *)malloc(sizeof(t_ps));
	if (!ps)
		ft_error(2);
	ps->ainfo = (t_stack *)malloc(sizeof(t_stack));
	if (!ps->ainfo)
	{
		free(ps);
		ft_error(2);
	}
	return (ps);
}

int	main(int argc, char **argv)
{
	long	*array;
	t_array	*index_array;
	t_ps	*ps;

	array = NULL;
	index_array = NULL;
	ps = init_push_swap(argc);
	ps->ainfo->size = parse_args(argc, argv, &array);
	if (ps->ainfo->size == -1)
		ps_error(ps);
	if (check_duplicates(array, ps->ainfo->size) == -1)
		array_error(array, ps);
	index_array = organize_array(array, ps->ainfo->size);
	if (!index_array)
		array_error(array, ps);
	ps->a = make_stack_a(index_array);
	free(index_array->array);
	free(index_array->index);
	free(index_array);
	ps->ainfo->id = 'a';
	push_swap(ps->a, ps->ainfo);
	free(ps);
	return (0);
}
