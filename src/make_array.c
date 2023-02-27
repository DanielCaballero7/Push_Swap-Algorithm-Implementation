/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:40:40 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/16 14:03:16 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*Check if args are digits; return number of digits*/
int	are_digits(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0' || str[0] == ' ')
		return (-1);
	while (str[i] != '\0' && (ft_isdigit(str[i])
			|| str[i] == ' ' || str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'
				|| str[i - 1] == '-' || str[i - 1] == '+'))
			return (-1);
		else if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '\0'
				|| str[i + 1] == '-' || str[i + 1] == '+'))
			return (-1);
		else
			i++;
	}
	return (ft_count(str, ' ') + 1);
}

/*
Transform into a array of ints.
INPUT: 
A string containing space separated integers or
a sequence of integer strings as separate command line arguments.
*/
int	to_int_array(int argc, char **argv, int nums, long **array)
{
	int		i;
	char	*str;
	long	*ptr;

	str = argv[1];
	i = 0;
	*array = (long *) malloc(sizeof(long) * nums);
	if (!array)
		return (-1);
	while (i < nums)
	{
		if (argc == 2)
		{
			(*array)[i] = ft_atol(str);
			if (i < nums - 1)
				str = ft_strchr(str, ' ') + 1;
		}
		else
			(*array)[i] = ft_atol(argv[i + 1]);
		i++;
	}
	return (0);
}

int	parse_args(int argc, char **argv, long **ptr)
{
	int		i;
	int		nums;

	i = 0;
	nums = 0;
	if (argc == 2)
		nums = are_digits(argv[1]);
	else
	{
		while (i++ < (argc - 1))
		{
			if (are_digits(argv[i]) != -1)
				nums += are_digits(argv[i]);
			else
				return (-1);
		}
	}
	if (nums == -1 || to_int_array(argc, argv, nums, ptr) == -1)
		return (-1);
	i = -1;
	while (++i < nums)
		if ((*ptr)[i] > 2147483647 || (*ptr)[i] < -2147483648)
			return (-1);
	return (nums);
}
