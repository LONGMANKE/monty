#include "monty.h"
void read_file(char *file, stack_t **stack)
{
	char *line;
	size_t i = 0;
	int line_count = 1, s;
	int check;
	int read;

	var_global.file = fopen(file, "r");

	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&var_global.buffer, &i,var_global.file) != -1))
	{
		line = parse_line(var_global.buffer, line_count);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = get_op_func(line, stack, line_count);
		if (s == 1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			exit(EXIT_FAILURE);
		}
		line_count++;
	}
	free(var_global.buffer);
	check = fclose(var_global.file);
	if (check == -1)
		exit(-1);
}
