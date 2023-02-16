#include "../inc/push_swap.h"

/*text parse_args*/
void	test_parse_args(void)
{
	int		argc;
	char	**argv;
	long	*ptr;
	int		nums;

	argc = 2;
	argv = malloc(sizeof(char *) * argc);
	argv[0] = "push_swap";
	argv[1] = "1 2 3 4 5 6 7 8 9 10";
	nums = are_digits(argv[1]);
	printf("nums: %d\n", nums);
	parse_args(argc, argv, &ptr);
	while (nums > 0)
	{
		printf("%ld\n", ptr[nums - 1]);
		nums--;
	}
}

int	main(void)
{
	int		argc;
	char	**argv;
	long	*ptr;
	int		nums;

	test_parse_args();
	return (0);
}