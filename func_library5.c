#include "alx.h"

/**
 * free_recurrent_data - free fields needed at each loop
 * @lungi: a pointer to struct
 *
 * Return:(void)
 */

void free_recurrent_data(_st *lungi)
{
	if (lungi->f)
		free_array_of_pointers(lungi->f);
	if (lungi->b)
		free(lungi->b);
	if (lungi->c)
		free(lungi->c);

	lungi->b = NULL;
	lungi->c = NULL;
	lungi->f = NULL;
}

/**
 * free_all_data - free field of data
 * @lungi: a pointer to struct
 *
 * Return:(void)
 */
void free_all_data(_st *lungi)
{
	if (lungi->e != 0)
	{
		if (close(lungi->e))
			perror(lungi->a);
	}
	free_recurrent_data(lungi);
	free_array_of_pointers(lungi->env);
	free_array_of_pointers(lungi->h);
}

/**
 * free_array_of_pointers - free a pointer of an array
 * @array: array of pointers
 *
 * Return: (void)
 */
void free_array_of_pointers(char **array)
{
	int i;

	if (array != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);

		free(array);
		array = NULL;
	}
}
