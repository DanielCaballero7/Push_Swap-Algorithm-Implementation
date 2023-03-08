#include "../inc/push_swap.h"

/*text parse_args*/
int	main(int argc, char **argv)
{
	long	*array;
	t_array	*index_array;
	t_stack	*stack_a;
	t_node	*node_a;
	//int	i = 0;

	stack_a = malloc(sizeof(t_stack));
	if (argc == 1 || !stack_a)
	{
		ft_putstr_fd(ERROR_ARGS, 2);
		return (-1);
	}
	stack_a->size = parse_args(argc, argv, &array);
	if (stack_a->size == -1)
	{
		ft_putstr_fd(ERROR_ARGS, 2);
		return (-1);
	}
	if (check_duplicates(array, stack_a->size) == -1)
	{
		ft_putstr_fd(ERROR_ARGS, 2);
		return (-1);
	}
	index_array = organize_array(array, stack_a->size);
	if (!index_array)
		return (-1);
	/*while (i < stack_a->size)
	{
		printf("%lu, %d\n", index_array->array[i], index_array->index[i]);
		i++;
	}*/
	node_a = make_stack_a(index_array);
	stack_a->id = 'a';
	push_swap(node_a, stack_a);
	return (0);
}