#include "alx.h"

/**
 * _token - A func that splits strings using delimiter
 * @lungi: a pointer to struct
 *
 * Return: Tokens
 */


void _token(_st *lungi)
{
	char *delimiter = " \t";
	int i, j, counter = 2, length;

	length = str_length(lungi->b);
	if (length)
	{
		if (lungi->b[length - 1] == '\n')
			lungi->b[length - 1] = '\0';
	}

	for (i = 0; lungi->b[i]; i++)
	{
		for (j = 0; delimiter[j]; j++)
		{
			if (lungi->b[i] == delimiter[j])
				counter++;
		}
	}

	lungi->f = malloc(counter * sizeof(char *));
	if (lungi->f == NULL)
	{
		perror(lungi->a);
		exit(errno);
	}
	i = 0;
	lungi->f[i] = str_duplicate(_strtok(lungi->b, delimiter));
	lungi->c = str_duplicate(lungi->f[0]);
	while (lungi->f[i++])
	{
		lungi->f[i] = str_duplicate(_strtok(NULL, delimiter));
	}
}
