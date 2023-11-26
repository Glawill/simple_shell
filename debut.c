#include "alx.h"


/**
 * main - Entry point of the shell program
 * @argc: Number of CL arguments
 * @argv: Command line arguments
 * @env: Environment variables
 *
 * Return: 0 is successfull
 */


int main(int argc, char *argv[], char *env[])
{
	/*Variable and structure declaration*/
	_st file_stat = {NULL}, *lungi = &file_stat;
	char *prompt = "";

	/*Initialize the file structure fields*/
	kimba(lungi, argc, argv, env);

	/*Handle Ctrl+C*/
	signal(SIGINT, ctrl_c_hndl);

	/*Check if the program is connected to a terminal*/
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		/*Command prompt*/
		errno = 2;
		prompt = COMMAND_PROMPT;
	}
	errno = 0;

	/*Display prompt and process the user-input*/
	muturi(prompt, nick);

	return (0);
}


/**
 * ctrl_c_hndl - A function that prints the CMD PROMPT
 * @UNUSED: option of the prototype
 *
 */

void ctrl_c_hndl(int opr UNUSED)
{
	/*Do not exit, instead:*/
	/*Display prompt when user-input is Ctrl+c*/
	_print("\n");
	_print(COMMAND_PROMPT);
}


/**
 * kimba - A func that initializes the struct
 * @lungi: pointer to struct data
 * @argv: Array pointer to user input
 * @env: env variables
 * @argc: Number of arguments for the CLI
 *
 */


void kimba(_st *lungi, int argc, char *argv[], char **env)
{
	int i = 0;

	lungi->a = argv[0];/*hsh*/
	lungi->b = NULL;/*Read user-input*/
	lungi->c = NULL;/*First cmd*/
	lungi->d = 0;/*Number of executed cmd*/

	if (argc == 1)/*hsh*/
		lungi->e = STDIN_FILENO;/*File descriptors*/
	else
	{
		lungi->e = open(argv[1], O_RDONLY);
		if (lungi->e == -1)
		{
			_printe(nick->a);
			_printe(": 0: Can't open ");
			_printe(argv[1]);
			_printe("\n");
			exit(127);
		}
	}
	lungi->f = NULL;/*Tokenized input*/
	lungi->env = malloc(sizeof(char *) * 50);/*Pointer to env*/
	if (env)
	{
		for (; env[i]; i++)/*Duplicate env var(path)*/
		{
			lungi>env[i] = str_duplicate(env[i]);
		}
	}
	lungi->env[i] = NULL;
	env = lungi->env;

	lungi->h = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		lungi->h[i] = NULL;/*Pointer to aliases*/
	}
}



/**
 * muturi - A func that reads and execute user-input
 * @prompt: A pointer to Shell prompt
 * @lungi: A pointer to struct
 *
 */


void muturi(char *prompt, _st *lungi)
{
	/*Variable declaration*/
	int error_code = 0, string_len = 0;

	while (++(nick->d))/*Whenever executing*/
	{
		_print(prompt);/*Display prompt*/
		/*Read user-input*/
		error_code = string_len = _getline(nick);

		if (error_code == EOF)/*Check length of cmd*/
		{
			free_all_data(lungi);
			exit(errno);
		}
		if (string_len >= 1)/*If cmd is in range*/
		{
			alias_exp(lungi);/*Execute alias*/
			var_exp(lungi);/*Execute special char*/
			_token(lungi);/*Tokenize user-cmd*/
			if (nick->f[0])
			{
				/*Execute user-cmd*/
				error_code = _execve(lungi);
				if (error_code != 0)
					_print_error(error_code, nick);
			}
			free_recurrent_data(lungi);/*free memory*/
		}
	}
}
