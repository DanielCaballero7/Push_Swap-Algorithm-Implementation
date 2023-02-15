/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:00:41 by dcaballe          #+#    #+#             */
/*   Updated: 2023/02/13 21:37:07 by dcaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//push_swap.h
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERROR_ARGS "Error\n argumentos incorectos"
# include <unistd.h>
# include "../libft/libft.h"

int	check_arg(char *str);
int	parse_string(char *str);
int	conver_string(char *str, long **ptr, int nums);
int	make_array(int argc, char **argv, int nums, long **array);
int	parse_args(int argc, char **argv, long **ptr);

#endif