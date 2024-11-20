/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:37 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/20 15:54:45 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>         // For perror(), printf()
# include <stdlib.h>        // For malloc(), free(), exit()
# include <unistd.h>        // For access(), fork(), write(), getcwd(), 
// chdir(), dup(), dup2(), pipe(), close(), read()
# include <fcntl.h>         // For open(), unlink()
# include <sys/types.h>     // For fork(), opendir(), readdir(), closedir()
# include <sys/wait.h>      // For wait(), waitpid(), wait3(), wait4()
# include <signal.h>        // For signal(), sigaction(), sigemptyset(),
//  sigaddset(), kill()
# include <dirent.h>        // For opendir(), readdir(), closedir()
# include <string.h>        // For strerror()
# include <termios.h>       // For tcsetattr(), tcgetattr()
# include <curses.h>        // For tgetent(), tgetflag(), tgetnum(), tgetstr(),
//  tgoto(), tputs()
# include <term.h>          // For tgetent(), tgetflag(), tgetnum(), tgetstr(),
//  tgoto(), tputs()
# include <sys/ioctl.h>     // For ioctl()
# include <sys/stat.h>      // For stat(), lstat(), fstat()
# include <readline/readline.h> // For readline(), add_history()
# include <readline/history.h>  // For rl_clear_history(), rl_on_new_line(),
//  rl_replace_line(), rl_redisplay()
# include <errno.h>         // For perror(), strerror()
// # include <sys/ttycom.h>    // For isatty(), ttyname(), ttyslot()

// Macros
# define PROMPT "minishell$ "

// Env struct
typedef struct s_environment
{
	char					*key;
	char					*value;
	struct s_environment	*next;
}	t_env;

// Command struct
typedef struct s_command
{
	char					*command;
	char					**args;
}	t_cmd;

// Token Type enum
typedef enum e_token_type
{
	NONE,
	WHITE,
	WORD,
	SQUOTE,
	DQUOTE,
	OPERATOR
}	t_type;

// Token struct
typedef struct s_token
{
	char					*str;
	t_type					type;
	struct s_token			*prev;
	struct s_token			*next;
}	t_tok;

// Main struct
typedef struct s_main
{
	t_env	*env_head;
	t_cmd	current_cmd;
	char	*user_input;
	t_tok	*tok_head;
	int		exit_status;
}	t_main;

// Function declarations
// core
void	f_execute(t_main *main);
void	f_handle_signals(void);
void	init(t_main *main, char *env[]);
void	f_extract_cmd(t_main *main, char *command_line);
// builtins
void	f_echo(t_main *main);
void	f_pwd(void);
void	f_env(t_main *main);
void	f_cd(t_main *main);
void	f_unset(t_main *main);
void	f_export(t_main *main);
int		is_builtin(char *command);
// env
char	*f_env_strtovalue(char *str);
int		f_env_add_back(t_env **p_head, char *key, char *value);
char	*f_env_keyvaluetostr(t_env *node);
char	*f_env_strtokey(char *str);
t_env	*f_env_find_key(t_env *head, char *key);
void	f_env_del_one(t_env **p_head, t_env *node);
t_env	*f_env_new(char *key, char *value);
t_env	*f_env_create_lnklst(char **env);
char	**f_env_create_2da(t_env *head);
void	f_env_del_list(t_env *head);
void	f_env_del_2da(char **env);
t_env	*f_env_last(t_env *head);
int		f_env_lstlen(t_env *head);
// utils
void	*f_memcpy(void *dest, const void *src, size_t n);
int		f_strcmp(char *str1, char *str2);
char	*f_strchr(const char *s, int c);
size_t	f_strlen(const char *s);
char	*f_strjoin(char const *s1, char const *s2);
char	**f_split(char const *s, char c);
char	*f_strdup(const char *s);
char	*f_strscmp(char *str1, int n, ...);
// token
int		f_get_token_end(char *str, int start);
void	f_tokenize(t_main *main);
int		f_tok_add_back(t_tok **p_head, char *str);
t_tok	*f_tok_last(t_tok *head);
t_tok	*f_tok_new(char *str);
void	f_print_tokens(t_main *main);
void	f_create_tokens(t_main *main);
t_tok	*f_tok_check_syntax(t_main *main);
void	f_tok_del_one(t_tok *tok);
void	f_unite_double_ops(t_main *main);
void	f_add_categories(t_main *main);

#endif // MINISHELL_H
