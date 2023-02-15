/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:58:17 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/15 11:38:33 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//proyecto push_swap 42
#include "../inc/push_swap.h"

/*Check if args are digits; return number of digits*/
int	are_digits(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0' || str[0] == ' ')
		return (-1);
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != '-'
			&& str[i] != '+')
			return (-1);
		if (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			return (-1);
		i++;
	}
	return (ft_count(str, ' ') + 1);
}

int	conver_string(char *str, long **ptr, int nums)
{
	static int	i;
	long		*array;

	array = *ptr;
	if (!i)
		i = 0;
	while (i < nums)
	{
		array[i] = ft_atoi(str);
		i++;
		if (i != nums)
		{
			str = ft_strchr(str, ' ');
			str++;
		}
	}
	return (0);
}

int	make_array(int argc, char **argv, int nums, long **array)
{
	int		i;
	int		j;
	int		status;

	i = 1;
	j = 0;
	*array = malloc(sizeof(long) * nums);
	if (!array)
		return (-1);
	while (i < argc)
	{
		nums = are_digits(argv[i]);
		if (nums == -1)
			return (-1);
		conver_string(argv[i], array, nums);
		i++;
	}
	return (0);
}

int	parse_args(int argc, char **argv, long **ptr)
{
	int		i;
	int		nums;
	int		status;

	i = 1;
	nums = 0;
	while (i < argc)
	{
		status = are_digits(argv[i]);
		if (status == -1)
			return (-1);
		nums += status;
		i++;
	}
	make_array(argc, argv, nums, ptr);
	return (0);
}

/*Comprueba si el argumento es una string de numeros o si son varios numeros
pasados como argumentos*/
/*
int	main(int argc, char **argv)
{
	int		i;
	int		nums;
	long	*array;

	i = 1;
	nums = 0;
	if (argc == 1)
	{
		write(1, ERROR_ARGS, sizeof(ERROR_ARGS));
		return (-1);
	}
	parse_args(argc, argv, &array);
	return (0);
}
*/
