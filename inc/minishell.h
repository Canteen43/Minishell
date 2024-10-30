/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:37 by kweihman          #+#    #+#             */
/*   Updated: 2024/10/30 14:38:37 by kweihman         ###   ########.fr       */
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

// Function declarations
// builtins
void	f_echo(int argc, char **argv, char **envp);
// Utils
int		f_strcmp(char *str1, char *str2);

#endif // MINISHELL_H
