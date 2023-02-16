/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:58:17 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/16 13:41:03 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//proyecto push_swap 42
#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	long	*array;

	if (argc == 1)
	{
		ft_putstr_fd(ERROR_ARGS, 2);
		return (-1);
	}
	else if (parse_args(argc, argv, &array) == -1)
	{
		ft_putstr_fd(ERROR_ARGS, 2);
		return (-1);
	}
	else
		return (0);
}
