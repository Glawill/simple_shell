#ifndef FUNC_LIBRARY_H
#define FUNC_LIBRARY_H


int _getline(_st *lungi);
char *_strtok(char *line, char *delim);
void free_array_of_pointers(char **directories);
void free_recurrent_data(_st *lungi);
void free_all_data(_st *lungi);
char *env_get_key(char *name, _st *lungi);
int env_set_key(char *key, char *value, _st *lungi);
int env_remove_key(char *key, _st *lungi);
void print_environ(_st *lungi);
int _print(char *string);
int _printe(char *string);
int _print_error(int errorcode, _st *lungi);
int str_length(char *string);
char *str_duplicate(char *string);
int str_compare(char *string1, char *string2, int number);
char *str_concat(char *string1, char *string2);
void str_reverse(char *string);
void long_to_string(long number, char *string, int base);
int _atoi(char *s);
int count_characters(char *string, char *character);


#endif /* FUNC_LIBRARY_H */
