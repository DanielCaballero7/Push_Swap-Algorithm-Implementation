/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:37:30 by dcaballe          #+#    #+#             */
/*   Updated: 2023/03/27 12:47:11 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:40:40 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/28 20:45:13 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_duplicates(const long *array, int nums)
{
	int		i;
	int		j;

	i = 0;
	while (i < nums)
	{
		j = i + 1;
		while (j < nums)
		{
			if (array[i] == array[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*fill_index(int *index, int nums)
{
	int	i;

	i = 1;
	while (i <= nums)
	{
		index[i - 1] = i - 1;
		i++;
	}
	return (index);
}

/*Check if args are digits; return number of digits*/
int	are_digits(const char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0' || str[0] == ' ')
		return (-1);
	while (str[i] != '\0' && (ft_checkdigit(str[i]) || str[i] == ' '))
	{
		if (str[i] == ' ' && (!ft_checkdigit(str[i + 1])
				||ft_issign(str[i - 1])))
			return (-1);
		else if (ft_issign(str[i]) && (!ft_checkdigit(str[i + 1])))
			return (-1);
		else
			i++;
	}
	if (!ft_isdigit(str[i]) && str[i] != '\0')
		return (-1);
	else
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
	int			i;
	const char	*str;

	str = argv[1];
	i = 0;
	*array = (long *) malloc(sizeof(long) * nums);
	if (*array == NULL)
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

int	parse_args(int argc, char **argv, long **array)
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
	if (nums <= 0 || to_int_array(argc, argv, nums, array) == -1)
		return (-1);
	i = -1;
	while (++i < nums)
		if ((*array)[i] > 2147483647 || (*array)[i] < -2147483648)
			return (-1);
	return (nums);
}
