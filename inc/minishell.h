/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:37 by kweihman          #+#    #+#             */
/*   Updated: 2024/11/17 13:38:59 by glevin           ###   ########.fr       */
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

// Global vars
# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// Macros
# define PROMPT "minishell$ "

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

// Main struct
typedef struct s_main
{
	t_env					*env_head;
	t_cmd					current_cmd;
}							t_main;

// Pipex struct
typedef struct s_pipex
{
	int						infile;
	int						outfile;
	char					**paths;

}							t_pipex;

// Function declarations
// core
void						f_execute(t_main *main);
void						f_handle_signals(void);
void						init(t_main *main, char *env[]);
void						f_extract_cmd(t_main *main, char *command_line);
// builtins
void						f_echo(t_main *main);
void						f_pwd(void);
void						f_env(t_main *main);
void						f_cd(t_main *main);
void						f_unset(t_main *main);
void						f_export(t_main *main);
int							is_builtin(char *command);
// env
char						*f_env_strtovalue(char *str);
int							f_env_add_back(t_env **p_head, char *key,
								char *value);
char						*f_env_keyvaluetostr(t_env *node);
char						*f_env_strtokey(char *str);
t_env						*f_env_find_key(t_env *head, char *key);
void						f_env_del_one(t_env **p_head, t_env *node);
t_env						*f_env_new(char *key, char *value);
t_env						*f_env_create_lnklst(char **env);
char						**f_env_create_2da(t_env *head);
void						f_env_del_list(t_env *head);
void						f_env_del_2da(char **env);
t_env						*f_env_last(t_env *head);
int							f_env_lstlen(t_env *head);
// utils
void						*f_memcpy(void *dest, const void *src, size_t n);
int							f_strcmp(char *str1, char *str2);
char						*f_strchr(const char *s, int c);
size_t						f_strlen(const char *s);
char						*f_strjoin(char const *s1, char const *s2);
char						**f_split(char const *s, char c);
int							f_strncmp(char *str1, char *str2, size_t n);

// execution
void						exit_clean(t_pipex *pipex, int ecode);
char						*get_cmd_path(char **paths, char *in_cmd);
int							open_file(t_pipex *pipex, char *filename, int i);
void						free_split(char **split);
void						here_doc(t_pipex *pipex, char *limiter, int argc);
void						execute(t_pipex *pipex, char *argv, char **envp);

// get next line
char						*get_next_line(int fd);
int							ft_istrchr(const char *str, int c);
char						*ft_strdup(const char *string);
char						*ft_substr(char const *s, unsigned int start,
								size_t len);
char						*ft_strjoin(char const *s1, char const *s2);

#endif // MINISHELL_H
