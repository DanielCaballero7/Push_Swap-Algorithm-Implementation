/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:21:52 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/28 20:46:06 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	sort_array(t_array *index_array)
{
	int	i;
	int	j;

	i = 0;
	while (i < index_array->size)
	{
		j = i + 1;
		while (j < index_array->size)
		{
			if ((index_array->array[i] > index_array->array[j]))
			{
				index_array->index[i]++;
				index_array->index[j]--;
			}
			j++;
		}
		i++;
	}
	i = 0;
	return (0);
}

t_array	*organize_array(long *array, int size)
{
	t_array	*index_array;

	index_array = malloc(sizeof(t_array));
	if (!index_array)
		return (NULL);
	index_array->array = array;
	index_array->index = malloc(sizeof(int) * size);
	if (!index_array->index)
		return (NULL);
	index_array->size = size;
	index_array->index = fill_index(index_array->index, size);
	sort_array(index_array);
	return (index_array);
}
