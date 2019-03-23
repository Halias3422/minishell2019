/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 13:35:26 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/23 14:14:39 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include <dirent.h>

typedef struct		s_shell
{
	char			**data;
	char			**path;
	char			*entry;
	char			**input;
	char			*cmd;
	char			*curr_dir;
}					t_shell;

typedef struct		s_setenv
{
	char			**data;
	char			*var_name;
}					t_setenv;

/*
**MAIN.C
*/

int					main(int ac, char **av, char **env);

/*
**MINISHELL.C
*/

void				read_input(t_shell *shell);
int					check_if_input_valid(t_shell *shell);
int					exec_command(t_shell *shell);

/*
**UTILS_TOOLS.C
*/

char				**free_db_tab(char **input);
char				*clean_entry(t_shell *shell);
char				**remove_first_backslash_n(t_shell *shell);
char				*get_curr_dir(char *pwd, char *curr_dir);
char				*get_pwd(t_shell *shell);
int					get_old_pwd_int(t_shell *shell);
int					get_pwd_int(t_shell *shell);

/*
**BUILTINS.C
*/

int					check_for_builtins(t_shell *shell);

/*
**MODIF_ENV_DATA.C
*/

char				**copy_env_data(char **data, char **env);
char				**change_data_pwd(char **data, char *path, t_shell *shell);

/*
**ECHO_BUILTIN.C
*/

int					handle_echo_builtin(t_shell *shell);

/*
**CD_BUILTIN.C
*/

int					handle_cd_builtin(t_shell *shell);

/*
**SETENV_BUILTIN.C
*/

int					handle_setenv_builtin(t_shell *shell);

/*
**UNSETENV_BUILTIN.C
*/

int					handle_unsetenv_builtin(t_shell *shell);

/*
**HANDLE_DOLLAR.C
*/

char				*replace_dollar_tilde_var(char *entry, t_shell *shell);
char				*put_home_in_entry(char *entry, t_shell *shell, int j,
					int i);

/*
**FREE.C
*/

void				exit_free(t_shell *shell);

#endif
