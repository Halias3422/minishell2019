/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 13:34:38 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 19:24:06 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int			exec_command(t_shell *shell)
{
	pid_t	father;

	father = fork();
	if (father > 0)
	{
		wait(&father);
		return (1);
	}
	else if (father == 0)
		execve(shell->cmd, shell->input, NULL);
	return (0);
}

int			check_if_input_valid(t_shell *shell)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (shell->path[i])
	{
		shell->cmd = shell->path[i];
		shell->path[i] = ft_strjoin(shell->path[i], shell->input[0]);
		j = ft_strlen(shell->path[i]) - 1;
		while (j >= 0 && shell->path[i][j] == '\n')
			j--;
		shell->path[i][j + 1] = '\0';
		if (access(shell->path[i], X_OK) == 0)
		{
			tmp = shell->path[i];
			shell->path[i] = shell->cmd;
			shell->cmd = tmp;
			return (i);
		}
		shell->path[i] = shell->cmd;
		i++;
	}
	return (-1);
}

void		read_input(t_shell *shell)
{
	int		ret;
	int		is_valid;
	int		is_father;
	int		is_builtin;

	is_father = 1;
	shell->curr_dir = NULL;
	shell->curr_dir = get_curr_dir(shell->data[6], shell->curr_dir);
	ft_printf("{B.T.red.}-> {eoc} {B.T.blue.}%s :{eoc} ", shell->curr_dir);
	while ((ret = read(0, shell->entry, 255)) && is_father == 1)
	{
		shell->entry = clean_entry(shell);
		is_builtin = check_for_builtins(shell);
		if (is_builtin == 0)
		{
			shell->input = ft_strsplit(shell->entry, ' ');
			shell->path = remove_first_backslash_n(shell);
			is_valid = check_if_input_valid(shell);
			if (is_valid > -1)
				is_father = exec_command(shell);
		shell->input = free_db_tab(shell->input);
		}
		if (is_father == 1)
		{
			shell->curr_dir = get_curr_dir(shell->data[6], shell->curr_dir);
			ft_printf("{B.T.red.}-> {eoc} {B.T.blue.}%s :{eoc} ", shell->curr_dir);
		}
		free(shell->entry);
		shell->entry = ft_strnew(255);
	}
}
