#include "monty.h"
global_var  var_global;
int main(int argc, char **argv)
{
	stack_t *stack;
	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(argv[1], &stack);
	free_dlistint(stack);
	return (0);
}
