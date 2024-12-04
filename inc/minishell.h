/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:37 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/04 13:39:25 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>  // For perror(), printf()
# include <stdlib.h> // For malloc(), free(), exit()
# include <unistd.h> // For access(), fork(), write(), getcwd(),
// chdir(), dup(), dup2(), pipe(), close(), read()
# include <fcntl.h>     // For open(), unlink()
# include <signal.h>    // For signal(), sigaction(), sigemptyset(),
# include <sys/types.h> // For fork(), opendir(), readdir(), closedir()
# include <sys/wait.h>  // For wait(), waitpid(), wait3(), wait4()
//  sigaddset(), kill()
# include <curses.h>  // For tgetent(), tgetflag(), tgetnum(), tgetstr(),
# include <dirent.h>  // For opendir(), readdir(), closedir()
# include <string.h>  // For strerror()
# include <termios.h> // For tcsetattr(), tcgetattr()
//  tgoto(), tputs()
# include <term.h> // For tgetent(), tgetflag(), tgetnum(), tgetstr(),
//  tgoto(), tputs()
# include <readline/history.h>  // For rl_clear_history(), rl_on_new_line(),
# include <readline/readline.h> // For readline(), add_history()
# include <sys/ioctl.h>         // For ioctl()
# include <sys/stat.h>          // For stat(), lstat(), fstat()
//  rl_replace_line(), rl_redisplay()
# include <errno.h> // For perror(), strerror()
// # include <sys/ttycom.h>    // For isatty(), ttyname(), ttyslot()

// Macros
# define PROMPT "minishell$ "
# define MALLOCFAIL "malloc() failed"
# define SIGFAIL "signal function failed"

# define SIGMODE_INTERACTIVE 1
# define SIGMODE_RESET 2
# define SIGMODE_WAITFORCHILD 3
# define SIGMODE_HEREDOC 4

// Env struct
typedef struct s_environment
{
	char					*key;
	char					*value;
	struct s_environment	*next;
}							t_env;

// Command struct
typedef struct s_command
{
	char					*command;
	char					**args;
}							t_cmd;

// Garbage Collector
typedef struct s_gnode
{
	void					*ptr;
	struct s_gnode			*next;
}							t_gnode;

// Token Type enum
typedef enum e_token_type
{
	NONE,
	WHITE,
	WORD,
	SQUOTE,
	DQUOTE,
	COMMAND,
	PIPE,
	REDIR_OUT,
	REDIR_OUT_APP,
	REDIR_IN,
	REDIR_HEREDOC,
}							t_type;

// Token struct
typedef struct s_token
{
	struct s_token			*prev;
	struct s_token			*next;
	t_type					type;
	char					*str;
	char					**args;
}							t_tok;

// Main struct
typedef struct s_main
{
	t_env					*env_head;
	t_cmd					current_cmd;
	char					*user_input;
	t_tok					*tok_head;
	int						exit_status;
	t_gnode					*gc_head;
	int						stdin_copy;
	int						stdout_copy;
}							t_main;

// Pipex struct
typedef struct s_pipex
{
	int						infile;
	int						outfile;
	int						fd[2];
	char *const *envp;
	char					**paths;

}							t_pipex;

// Function declarations
// core
int							f_execute_builtin(t_main *main, t_tok *tok);
void						f_signal_setup(int type);
void						init(t_main *main, char *env[]);
void						f_extract_cmd(t_main *main, char *command_line);
void						*f_gc_malloc(t_main *main, size_t size);
void						f_gc_clean(t_main *main);
t_gnode						*f_gc_add_node(t_main *main, void *ptr);
void						f_free_and_exit(t_main *main, char *message,
								int code);

// builtins
void						f_echo(t_main *main);
void						f_pwd(t_main *main);
void						f_env(t_main *main);
void						f_cd(t_main *main);
void						f_unset(t_main *main);
void						f_export(t_main *main);

// env
char						*f_env_strtovalue(t_main *main, char *str);
void						f_env_add_back(t_main *main, char *key,
								char *value);
char						*f_env_keyvaluetostr(t_main *main, t_env *node);
char						*f_env_strtokey(t_main *main, char *str);
t_env						*f_env_find_key(t_env *head, char *key);
void						f_env_remove_one(t_main *main, t_env *node);
void						f_tok_remove_one_universal(t_main *main,
								t_tok *tok);
t_env						*f_env_new(t_main *main, char *key, char *value);
void						f_env_create_lnklst(t_main *main, char **env);
char						**f_env_create_2da(t_main *main);
void						f_env_del_list(t_env *head);
void						f_env_del_2da(char **env);
t_env						*f_env_last(t_env *head);
int							f_env_lstlen(t_env *head);

// utils
void						*f_memcpy(void *dest, const void *src, size_t n);
int							f_strcmp(char *str1, char *str2);
char						*f_strchr(const char *s, int c);
size_t						f_strlen(const char *s);
char						*f_strjoin(t_main *main, char const *s1,
								char const *s2);
char						**f_split(t_main *main, char const *s, char c);
char						*f_strdup(t_main *main, const char *s);
char						*f_strscmp(char *str1, int n, ...);
int							f_strncmp(char *str1, char *str2, size_t n);
void						f_strncpy(char *dest, char *src, size_t n);
void						f_strcpy(char *dest, char *src);
bool						f_is_alpha(char c);
bool						f_is_dig(char c);
void						f_strncpy(char *dest, char *src, size_t n);
void						f_strcpy(char *dest, char *src);
bool						f_is_alpha(char c);
bool						f_is_dig(char c);
char						*f_itoa(t_main *main, int n);

// token
int							f_get_token_end(char *str, int start);
void						f_tokenize(t_main *main);
int							f_tok_add_back(t_main *main, char *str);
t_tok						*f_tok_last(t_tok *head);
t_tok						*f_tok_new(t_main *main, char *str);
void						f_print_tokens(t_main *main);
void						f_create_tokens(t_main *main);
t_tok						*f_tok_check_syntax(t_main *main);
void						f_tok_remove_one(t_tok *tok);
void						f_tok_remove_one(t_tok *tok);
void						f_unite_double_ops(t_main *main);
void						f_add_categories(t_main *main);
void						f_expand_variables(t_main *main);
char						*f_var_end(char *str);
char						*f_var_find_key(t_main *main, char *start,
								char *end);
char						*f_var_new_string(t_main *main, char *oldstr,
								char *valstr, char *end);
void						f_resolve_quotes(t_main *main);
void						f_join_tokens(t_main *main);
void						f_delete_white_toks(t_main *main);
void						f_add_arg_to_tok(t_main *main, char *arg,
								t_tok *tok);
void						f_toks_to_cmds_n_args(t_main *main);
void						f_expand_variables(t_main *main);
char						*f_var_end(char *str);
char						*f_var_find_key(t_main *main, char *start,
								char *end);
char						*f_var_new_string(t_main *main, char *oldstr,
								char *valstr, char *end);
void						f_resolve_quotes(t_main *main);
void						f_join_tokens(t_main *main);
void						f_delete_white_toks(t_main *main);
void						f_add_arg_to_tok(t_main *main, char *arg,
								t_tok *tok);
void						f_toks_to_cmds_n_args(t_main *main);
bool						f_tok_is_redir(t_tok *tok);

// execution
void						f_exit_clean(t_pipex *pipex, int ecode);
char						*f_get_cmd_path(t_main *main, char **paths,
								char *in_cmd);
int							f_open_file(t_pipex *pipex, char *filename, int i);
void						f_here_doc(t_pipex *pipex, char *limiter, int argc);
void						f_do_pipe(t_main *main, t_pipex *pipex, t_tok *tok);
void						f_init_pipex(t_pipex *pipex, t_main *main);
void						f_set_redirects(t_pipex *pipex, t_main *main);
void						f_do_execute(t_main *main, t_pipex *pipex,
								t_tok *tok);
void						f_execution(t_main *main);
t_tok						*f_find_final_cmd(t_main *main);
void						f_final_execute(t_main *main, t_pipex *pipex,
								t_tok *tok);

// get next line
char						*get_next_line(int fd);
int							ft_istrchr(const char *str, int c);
char						*ft_strdup(const char *string);
char						*ft_substr(char const *s, unsigned int start,
								size_t len);
char						*ft_strjoin(char const *s1, char const *s2);

#endif // MINISHELL_H
