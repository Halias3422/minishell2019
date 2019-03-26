/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 13:34:38 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 11:12:08 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			exec_command(t_shell *shell)
{
	pid_t	father;

	father = fork();
	if (father > 0)
	{
		wait(&father);
		return (1);
	}
	else if (father == 0 && access(shell->cmd, X_OK) == 0)
	{
		if (execve(shell->cmd, shell->input, shell->data) == -1)
		{
			ft_printf("minishell: exec format error: %s\n", shell->entry);
			return (1);
		}
	}
	return (0);
}

int			check_permissions_input(t_shell *shell, int i, char *tmp)
{
	if (access(shell->path[i], X_OK) == 0)
	{
		tmp = ft_strnew(ft_strlen(shell->path[i]));
		tmp = ft_strcpy(tmp, shell->path[i]);
		free(shell->path[i]);
		shell->path[i] = shell->cmd;
		shell->cmd = ft_strnew(ft_strlen(tmp));
		shell->cmd = ft_strcpy(shell->cmd, tmp);
		free(tmp);
		return (i);
	}
	else if (access(shell->path[i], F_OK) == 0 && access(shell->path[i]
		, X_OK) != 0)
		return (-2);
	return (-1);
}

int			check_if_input_valid(t_shell *shell, int i, int j)
{
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (shell->path[i])
	{
		shell->cmd = shell->path[i];
		shell->path[i] = ft_strjoin(shell->path[i], shell->input[0]);
		j = ft_strlen(shell->path[i]) - 1;
		while (j >= 0 && shell->path[i][j] == '\n')
			j--;
		shell->path[i][j + 1] = '\0';
		j = check_permissions_input(shell, i, tmp);
		if (j != -1)
			return (j);
		free(shell->path[i]);
		shell->path[i] = ft_strjoin(get_pwd(), "/");
		shell->path[i] = ft_strjoin(shell->path[i], shell->input[0]);
		j = check_permissions_input(shell, i, tmp);
		if (j != -1)
			return (j);
		shell->path[i] = shell->cmd;
		i++;
	}
	return (-1);
}

void		input_is_not_builtin(t_shell *shell, int is_father)
{
	int		is_valid;
	int		i;
	int		j;

	i = 0;
	j = 0;
	shell->input = ft_strsplit(shell->entry, ' ');
	shell->path = remove_first_backslash_n(shell);
	is_valid = check_if_input_valid(shell, i, j);
	if (is_valid > -1)
	{
		is_father = exec_command(shell);
		free(shell->cmd);
	}
	else if (is_valid == -2)
		ft_printf("minishell: permission denied: %s\n", shell->input[0]);
	else
		ft_printf("minishell: command not found: %s\n", shell->entry);
	shell->input = free_db_tab(shell->input);
}

void		read_input(t_shell *shell)
{
	int		ret;
	int		is_father;
	int		is_builtin;

	is_father = 1;
	shell->curr_dir = get_curr_dir(shell->curr_dir);
	ft_printf("{B.T.red.}-> {eoc} {B.T.blue.}%s :{eoc} ", shell->curr_dir);
	free(shell->curr_dir);
	while ((ret = read(0, shell->entry, 255)) && is_father == 1)
	{
		shell->entry = clean_entry(shell);
		shell->entry = replace_dollar_tilde_var(shell->entry, shell);
		is_builtin = check_for_builtins(shell);
		if (is_builtin == 0)
			input_is_not_builtin(shell, is_father);
		if (is_father == 1)
		{
			shell->curr_dir = get_curr_dir(shell->curr_dir);
			ft_printf("{B.T.red.}-> {eoc} {B.T.blue.}%s :{eoc} ",
					shell->curr_dir);
			free(shell->curr_dir);
		}
		free(shell->entry);
		shell->entry = ft_strnew(255);
	}
}
