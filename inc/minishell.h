/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:37 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/15 18:11:29 by kweihman         ###   ########.fr       */
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
# include <limits.h> // For INT_MAX and INT_MIN

// Macros
# define PROMPT "minishell$ "
# define HEREDOC_PROMPT "> "

# define MALLOCFAIL "malloc() failed, exiting minishell"
# define SIGFAIL "signal function failed, exiting minishell"
# define PIPEFAIL "pipe() failed, exiting minishell"
# define FORKFAIL "fork() failed, exiting minishell"
# define MISSINGFILEFAIL " No such file or directory"
# define DIRFAIL " Is a directory"
# define CMDFAIL " command not found"
# define PERMDENIED " Permission denied"
# define GENERICFILEFAIL " Failed to open file"

# define SIGMODE_INTERACTIVE 1
# define SIGMODE_RESET 2
# define SIGMODE_WAITFORCHILD 3
# define SIGMODE_HEREDOC 4

# define READ 0
# define WRITE 1

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
	struct s_token			*redir_head;
	int						heredoc_fd;
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
	char					**envp;
	char					**paths;

}							t_pipex;

// Function declarations
// core
int							f_do_builtin(t_main *main, t_tok *tok);
void						f_signal_setup(int type);
void						init(t_main *main, char *env[]);
void						f_extract_cmd(t_main *main, char *command_line);
void						*f_gc_malloc(t_main *main, size_t size);
void						f_gc_clean(t_main *main);
t_gnode						*f_gc_add_node(t_main *main, void *ptr);
void						f_free_and_exit(t_main *main, char *message,
								int code);
void						f_exit(t_main *main, t_tok *tok);

// builtins
void						f_echo(t_main *main, t_tok *tok);
void						f_pwd(t_main *main);
void						f_env(t_main *main);
void						f_cd(t_main *main, t_tok *tok);
void						f_unset(t_main *main, t_tok *tok);
void						f_export(t_main *main, t_tok *tok);

// env
char						*f_env_strtovalue(t_main *main, char *str);
void						f_env_add_back(t_main *main, char *key,
								char *value);
char						*f_env_keyvaluetostr(t_main *main, t_env *node);
char						*f_env_strtokey(t_main *main, char *str);
t_env						*f_env_find_key(t_env *head, char *key);
void						f_env_remove_one(t_main *main, t_env *node);
void						f_tok_remove_one_universal(t_tok **p_head,
								t_tok *tok);
t_env						*f_env_new(t_main *main, char *key, char *value);
void						f_env_create_lnklst(t_main *main, char **env);
char						**f_env_create_2da(t_main *main);
void						f_env_del_list(t_env *head);
void						f_env_del_2da(char **env);
t_env						*f_env_last(t_env *head);
int							f_env_lstlen(t_env *head);
void						f_increase_shlvl(t_main *main);

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
int							f_atoi_mod(char *str, int *num);
int							f_atoi(const char *str);
int							f_array_length(char **arr);

// token
bool						f_only_white_tokens(t_main *main);
int							f_get_token_end(char *str, int start);
int							f_tokenize(t_main *main);
int							f_tok_add_back(t_main *main, char *str);
t_tok						*f_tok_last(t_tok *tok);
t_tok						*f_tok_new(t_main *main, char *str);
void						f_print_tokens(t_main *main);
void						f_delete_empty_tokens(t_main *main);
int							f_create_tokens(t_main *main);
int							f_tok_check_syntax(t_main *main);
void						f_tok_remove_one(t_tok *tok);
void						f_tok_remove_one(t_tok *tok);
void						f_unite_double_ops(t_main *main);
void						f_add_categories(t_main *main);
void						f_do_expansions_for_toks(t_main *main);
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
void						f_do_expansions_for_toks(t_main *main);
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
bool						f_is_operator(t_tok *tok);
void						f_add_redirs_to_cmds(t_main *main);
void						f_delete_pipes(t_main *main);
bool						f_contains_heredoc(t_main *main);
void						f_do_expansions_in_str(t_main *main, char **p_str);
char						*f_expandable_dollar_sign(char *str);
bool						f_is_builtin(t_tok *tok);

// execution
char						*f_get_cmd_path(t_main *main, char **paths,
								char *in_cmd);
int							f_open_file(t_pipex *pipex, char *filename, int i);
int							f_do_heredoc(t_main *main, t_tok *redir);
void						f_handle_cmd(t_main *main, t_pipex *pipex,
								t_tok *tok);
void						f_init_pipex(t_pipex *pipex, t_main *main);
void						f_set_redirects(t_pipex *pipex, t_tok *tok);
void						f_do_execute(t_main *main, t_pipex *pipex,
								t_tok *tok);
void						f_execution(t_main *main);
void						f_handle_final_cmd(t_main *main, t_pipex *pipex,
								t_tok *tok);
void						f_handle_single_cmd(t_main *main, t_pipex *pipex,
								t_tok *tok);
void						f_handle_waits(t_main *main, pid_t pid);
void						f_execute_child(t_main *main, t_pipex *pipex,
								t_tok *tok);
void						f_do_child(t_main *main, t_pipex *pipex, t_tok *tok,
								int is_final);
int							f_resolve_heredocs(t_main *main);

// get next line
int							ft_istrchr(const char *str, int c);
char						*ft_strdup(const char *string);
char						*ft_substr(char const *s, unsigned int start,
								size_t len);
char						*ft_strjoin(char const *s1, char const *s2);

#endif // MINISHELL_H
