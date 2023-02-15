#include "../inc/push_swap.h"

/*test check_arg with a str of numbers, with a str with more than 1 space, with numbers and chars*/
void	test_check_arg(void)
{
	char	*str;
	int		status;

	str = "1 2 3 4 5 6 7 8 9 10";
	status = check_arg(str);
	printf("Cantidad de numeros: %d\n", status);
	str = "1 2 3 4 5 6 7 8 9 10  ";
	status = check_arg(str);
	printf("Cantidad de numeros: %d\n", status);
	str = "1 2 3 4 5 6 7 8 9 10 1a";
	status = check_arg(str);
	printf("Cantidad de numeros: %d\n", status);
	str = " 1 2 3 4 5 6 7 8 9 10 1";
	status = check_arg(str);
	printf("Cantidad de numeros: %d\n", status);
	str = "1 2 3 4 5 6 7 8 9 10 1 ";
	status = check_arg(str);
	printf("Cantidad de numeros: %d\n", status);
	str = "1 2 3 4 5 6a 7 8 9 10 1";
	status = check_arg(str);
	printf("Cantidad de numeros: %d\n", status);
}

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
	nums = parse_string(argv[1]);
	printf("Parse_string: %d\n", nums);
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
	test_check_arg();
	return (0);
}