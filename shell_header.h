#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

/**
 * struct built_in - Represents a built-in function and its associated command
 * @command: The command typed by the user
 * @fct: Pointer to the function that handles the built-in command
 */
typedef struct built_in
{
	char *command;
	int (*fct)(char *command, char **args, char ***env);
} bltin;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <errno.h>

char *get_cmd();
char **tokenize_args(char *buf);
int exec_cmd(char *command, char **args, char ***env, char *exec_file);

char *handle_cmnt(char *command);

int own_execve(char **args, char **env, char *exec_file);

char *own_strtok(char *str, const char *delim);

char *track_path(char *command, char **env);
char *find_path(char **env);
char *cmd_path(char *command, char *path);
char *correct_path(char *dir, char *cmd_name);

char **cpy_env(char **env);
char *copy_str(char *str);

/* C Standard Functions */
int own_strlen(char *str);
char *own_strcpy(char *copy, char *str);
int own_strcmp(char *str1, char *str2);
size_t array_len(char **str);
int own_atoi(char *n);

void free_array(char **arr);

/* Handle Built-in functions */
int (*is_built_in(char *command))(char *, char **, char ***);
int exit_program(char *command, char **args, char ***env);
int print_env(char *command, char **args, char ***env);
int setenv_var(char *command, char **args, char ***env);
int unsetenv_var(char *command, char **args, char ***env);

/* Change directory */
int change_dir(__attribute__((unused))char *command, char **args, char ***env);
char *find_dir_val(char **env, char *var);
int update_prev_dir(char **env);
int update_old_pwd(char **env, char *val);
int is_similar(char *str1, char *str2);
char *find_env_var(char **env, char *var);
char *get_dir_val(char *home);


/* Built in functions supplements*/
int already_exist(char *var, char **env);
char *find_var(char *env_var);
char **create_var(char **env, char *name, char *value);
char *update_var(char *value, char **env, int indx);
char **allocate_sp(char **env);
char *new_varToAdd(char *name, char *value);
char **delete_var(char **env, int indx);

/* Handle and Print Error */
void print_err(char *cmd_name, char *cmd, char *error, char *text);
unsigned int print_exec_prog(char *buff, char *exec, int n);
unsigned int add_command(char *buff, char *cmd, unsigned int n);
unsigned int add_error_msg(char *buff, char *error, unsigned int n);
unsigned int add_more_text(char *buff, char *text, char indx, unsigned int n);


#endif /* SHELL_HEADER_H */
