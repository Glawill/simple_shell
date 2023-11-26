#include "alx.h"


/**
 * blt_in_ext - A func that quits the shell program
 * @lungi: A pointer to struct
 * Return: 0 if successfull
 *
 */


int blt_in_ext(_st *lungi)
{
	int i;

	if (lungi->f[1] != NULL)
	{
		/*Check argument data type*/
		for (i = 0; lungi->f[1][i]; i++)
			if ((lungi->f[1][i] < '0' || lungi->f[1][i] > '9')
				&& lungi->f[1][i] != '+')
			{
				/*For non-numeric args*/
				errno = 2;
				return (2);
			}
		errno = _atoi(lungi->f[1]);
	}
	free_all_data(lungi);
	exit(errno);
}


/**
 * blt_in_cd - A func that changes current dir
 * @lungi: A pointer to struct
 * Return: 0 if successfull
 *
 */


int blt_in_cd(_st *lungi)
{
	char *dir_home = env_get_key("HOME", lungi), *dir_old = NULL;
	char old_dir[128] = {0};
	int error_code = 0;

	if (lungi->f[1])
	{
		if (str_compare(lungi->f[1], "-", 0))
		{
			dir_old = env_get_key("OLDPWD", lungi);
			if (dir_old)
				error_code = st_wk_dir(lungi, dir_old);
			_print(env_get_key("PWD", lungi));
			_print("\n");

			return (error_code);
		}
		else
		{
			return (st_wk_dir(lungi, lungi->f[1]));
		}
	}
	else
	{
		if (!dir_home)
			dir_home = getcwd(old_dir, 128);

		return (st_wk_dir(lungi, dir_home));
	}
	return (0);
}


/**
 * st_wk_dir - Sets PWD
 * @lungi: A pointer to struct
 * @new_dir: A pointer to the path of new_dir
 *
 * Return: 0 if successfull
 */


int st_wk_dir(_st *lungi, char *new_dir)
{
	char old_dir[128] = {0};
	int err_code = 0;

	getcwd(old_dir, 128);

	if (!str_compare(old_dir, new_dir, 0))
	{
		err_code = chdir(new_dir);
		if (err_code == -1)
		{
			errno = 2;
			return (3);
		}
		env_set_key("PWD", new_dir, lungi);
	}
	env_set_key("OLDPWD", old_dir, lungi);
	return (0);
}


/**
 * blt_in_hlp - A func that displays env variables
 * @lungi: A pointer to struct
 *
 * Return: 0 if successfull
 */


int blt_in_hlp(_st *lungi)
{
	int i, length = 0;
	char *van[6] = {NULL};

	van[0] = HELP_INFO_SEARCH;
	if (lungi->f[1] == NULL)
	{
		_print(van[0] + 6);
		return (1);
	}
	if (lungi->f[2] != NULL)
	{
		errno = E2BIG;
		perror(lungi->c);
		return (5);
	}
	van[1] = EXIT_HELP_INFO;
	van[2] = ENVIRONMENT_HELP_INFO;
	van[3] = SETENV_HELP_INFO;
	van[4] = UNSETENV_HELP_INFO;
	van[5] = CD_HELP_INFO;

	for (i = 0; van[i]; i++)
	{
		length = str_length(lungi->f[1]);
		if (str_compare(lungi->f[1], van[i], length))
		{
			_print(van[i] + length + 1);
			return (1);
		}
	}
	errno = EINVAL;
	perror(lungi->c);
	return (0);
}


/**
 * blt_in_alias - A func that sets aliases
 * @lungi: A pointer to struct
 *
 * Return: 0 for successfull code
 */


int blt_in_alias(_st *lungi)
{
	int i = 0;

	/*print env variables*/
	if (lungi->f[1] == NULL)
		return (p_alias(lungi, NULL));

	while (nick->f[++i])
	{
		/*Set env variables*/
		if (count_characters(lungi->f[i], "="))
			set_alias(lungi->f[i], lungi);
		else
			p_alias(lungi, lungi->f[i]);
	}

	return (0);
}
