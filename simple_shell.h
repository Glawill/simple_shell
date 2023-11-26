#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H


void kimba(_st *lungi, int arc, char *argv[], char **env);
void muturi(char *prompt, _st *lungi);
void ctrl_c_hndl(int opr UNUSED);
int lgc_ops(char *array_commands[], int i, char array_operators[]);
void var_exp(_st *lungi);
void alias_exp(_st *lungi);
int add_buf(char *buffer, char *str_to_add);
void _token(_st *lungi);
int _execve(_st *lungi);
int blt_in_lst(_st *lungi);
int p_alias(_st *lungi, char *alias);
char *alias_get(_st *lungi, char *alias);
int set_alias(char *alias_string, _st *lungi);
char **_tok(_st *lungi);
int prog_fnd(_st *lungi);


#endif
