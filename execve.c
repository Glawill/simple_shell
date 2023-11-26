#include "alx.h"

/**
 * _execve - executes a command.
 * @lungi: a pointer to struct
 * Return: 0 if successfull.
 */
int _execve(_st *lungi)
{
	/*variable declaration*/
	int retval = 0, status;
	pid_t pidd;

	retval = blt_in_lst(lungi);
	if (retval != -1)/*checks if the cmd is a blt-in*/
		return (retval);

	retval = prog_fnd(lungi);
	if (retval)/*checks if cmd is execve file*/
	{
		return (retval);
	}
	else
	{
		/* create a child process */
		pidd = fork();
		if (pidd == -1)
		{
			perror(lungi->c);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{
			/* execute the program*/
			retval = execve(lungi->f[0], lungi->f, lungi->env);
			if (retval == -1)
				perror(lungi->c), exit(EXIT_FAILURE);
		}
		else
		{
			/* wait then check exit status of the child */
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
