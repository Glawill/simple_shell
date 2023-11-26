#ifndef BUILTINS_H
#define BUILTINS_H


/* Builtin prototypes */
int blt_in_ext(_st *lungi);
int blt_in_cd(_st *lungi);
int st_wk_dir(_st lungi, char *new_dir);
int blt_in_hlp(_st *lungi);
int blt_in_alias(_st lungi);
int blt_in_env(_st *lungi);
int blt_set_env(_st *lungi);
int blt_in_unset_env(_st *lungi);
int blt_in_lst(_st *lungi);

#endif /* BUILTINS_H */
