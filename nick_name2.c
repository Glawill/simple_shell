#include "alx.h"


/**
 * p_alias - add or remove alias
 * @lungi: a pointer to struct
 * @alias: name to  be printed
 *
 * Return: 0 if successfull
 */

int p_alias(_st *lungi, char *alias)
{
	int i, j, alias_length;
	char buffer[250] = {'\0'};

	if (lungi->h)
	{
		alias_length = str_length(alias);
		for (i = 0; lungi->h[i]; i++)
		{
			if (!alias || (str_compare(nick->h[i], alias, alias_length)
				&&	lungi->h[i][alias_length] == '='))
			{
				for (j = 0; lungi->h[i][j]; j++)
				{
					buffer[j] = lungi->h[i][j];
					if (lungi->h[i][j] == '=')
						break;
				}
				buffer[j + 1] = '\0';
				add_buf(buffer, "'");
				add_buf(buffer, lungi->h[i] + j + 1);
				add_buf(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}


/**
 * alias_get - add or remove alias
 * @lungi: a pointer to struct.
 * @name: name of the  alias.
 *
 * Return: 0 if successfull.
 */

char *alias_get(_st *lungi, char *name)
{
	int i, alias_length;

	if (name == NULL || lungi->h == NULL)
		return (NULL);

	alias_length = str_length(name);

	for (i = 0; nick->h[i]; i++)
	{
		/* Iterates through the environ and check for coincidence of the varname */
		if (str_compare(name, lungi->h[i], alias_length) &&
			lungi->h[i][alias_length] == '=')
		{
			return (nick->h[i] + alias_length + 1);
		}
	}

	return (NULL);

}


/**
 * set_alias - add or remove alias
 * @alias_string: set in the alias in the form (name = 'value')
 * @lungi: a pointer to struct
 * Return: 0 if successfull.
 */

int set_alias(char *alias_string, _st *lungi)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	if (alias_string == NULL ||  lungi->h == NULL)
		return (1);

	/* Iterates alias to find = char */
	for (i = 0; alias_string[i]; i++)
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
		{
			temp = alias_get(nick, alias_string + i + 1);
			break;
		}

	/* Iterates through the alias list and check for coincidence of the varname */
	for (j = 0; lungi->h[j]; j++)
		if (str_compare(buffer, lungi->h[j], i) &&
			lungi->h[j][i] == '=')
		{
			free(lungi->h[j]);
			break;
		}

	/* add the alias */
	if (temp)
	{
		add_buf(buffer, "=");
		add_buf(buffer, temp);
		lungi->h[j] = str_duplicate(buffer);
	}
	else
		lungi>h[j] = str_duplicate(alias_string);
	return (0);
}
