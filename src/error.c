/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:01:31 by dcaballe          #+#    #+#             */
/*   Updated: 2023/03/27 15:01:31 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	array_error(long *array, t_ps *ps)
{
	free(array);
	ps_error(ps);
}

void	ps_error(t_ps *ps)
{
	ft_putstr_fd("Error\n", 2);
	free(ps->ainfo);
	free(ps);
	exit(1);
}

void	ft_error(int fd)
{
	ft_putstr_fd("Error\n", fd);
	exit(1);
}
