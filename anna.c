#include "alx.h"

/**
 * blt_in_env - displays environment variables
 * @nick: a pointer to struct
 * Return: 0 if sucessful, or otherwise if fails.
 */
int blt_in_env(_st *lungi)
{
	int i;
	char cpname[50] = {'\0'};
	char *var_copy = NULL;

	/* check if it a NULL argument */
	if (lungi->f[1] == NULL)
		print_environ(lungi);
	else
	{
		for (i = 0; lungi->f[1][i]; i++)
		{
			if (lungi->f[1][i] == '=')
			{
				var_copy = str_duplicate(env_get_key(cpname, lungi));
				if (var_copy != NULL)
					env_set_key(cpname, lungi->f[1] + i + 1, lungi);

				/* print the environ */
				print_environ(lungi);
				if (env_get_key(cpname, lungi) == NULL)
				{
					_print(lungi->f[1]);
					_print("\n");
				}
				else
				{
					env_set_key(cpname, var_copy, lungi);
					free(var_copy);
				}
				return (0);
			}
			cpname[i] = lungi->f[1][i];
		}
		errno = 2;
		perror(lungi->c);
		errno = 127;
	}
	return (0);
}

/**
 * blt_set_env - a function that set env variables.
 * @nick:a pointer to struct.
 * Return: 0 if sucessfull.
 */

int blt_set_env(_st *lungi)
{
	if (lungi->f[1] == NULL || lungi->f[2] == NULL)
		return (0);
	if (lungi->f[3] != NULL)
	{
		errno = E2BIG;
		perror(lungi->c);
		return (5);
	}

	env_set_key(lungi->f[1], lungi->f[2], lungi);

	return (0);
}

/**
 * blt_in_unset_env - a function that unsets env variables.
 * @nick: a pointer to struct
 * Return: 0 if successfull.
 */
int blt_in_unset_env(_st *lungi)
{
	if (lungi->f[1] == NULL)
		return (0);
	if (lungi->f[2] != NULL)
	{
		errno = E2BIG;
		perror(lungi->c);
		return (5);
	}
	env_remove_key(lungi->f[1], nick);

	return (0);
}
