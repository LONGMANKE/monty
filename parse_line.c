#include "monty.h"
char *parse_line(char *buffer, unsigned int line_num)
{
	char *op_code, *push, *arg;

	push = "push";

	op_code = strtok(buffer, "\n ");
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (isnum(arg) == 1 && arg != NULL)
			var_global.push_arg = atoi(arg);
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}
