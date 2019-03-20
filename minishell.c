/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 13:34:38 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 15:09:32 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

char		**copy_env_data(char **data, char **env)
{
	int		i;
	int		len;

	data = (char**)malloc(sizeof(char*) * 33 + 1);
	data[33] = NULL;
	i = 0;
	while (env[i])
	{
		len = ft_strlen(env[i]);
		data[i] = (char*)malloc(sizeof(char) * len + 1);
		data[i] = ft_strcpy(data[i], env[i]);
		i++;
	}
	return (data);
}

char		*get_curr_dir(char *pwd, char *curr_dir)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (pwd[i])
		i++;
	j = i;
	while (j >= 0 && pwd[j - 1] != '/')
		j--;
	curr_dir = (char*)malloc(sizeof(char) * (i - j) + 1);
	while (j < i)
		curr_dir[k++] = pwd[j++];
	curr_dir[k] = '\0';
	return (curr_dir);
}
/*
void		call_command(char *cmd, char **av, char *input, char **data, pid_t father)
{
	int		ret;
	char	*curr_dir;

	curr_dir = NULL;
	curr_dir = get_curr_dir(data[6], curr_dir);
	if (father > 0)
		wait(&father);
	else if (father == 0)
	{
		while ((ret = read(0, input, 255)))
		{
			if (ft_strncmp(input, "env", 3) == 0)
				ft_printf("%T\n", data);
			else
				execve(cmd, av, NULL);
		}
	}
}

void		read_input(char *input, char **av, char **data)
{
	int		ret;
	char	*cmd;
	char	*curr_dir;
	pid_t	father;

	curr_dir = NULL;
	curr_dir = get_curr_dir(data[6], curr_dir);
		ft_printf("ICI{B.T.red.} -> {eoc} {B.T.blue.}%s :{eoc} ", curr_dir);
	while ((ret = read(0, input, 255)))
	{
		cmd = ft_strnew(0);
		cmd = ft_strjoin(cmd, "/bin/");
		cmd = free_strjoin(cmd, input);
		cmd[ft_strlen(cmd) - 1] = '\0';
		if (ft_strncmp(input, "exit", 4) == 0)
		{
			ft_printf("exiting\n");
			exit(0);
		}
		else if (ft_strcmp(cmd, "/bin") != 0)
		{
			ft_printf("cmd = %s\n", cmd);
			call_command(cmd, av, input, data, father);
			ft_printf("LA{B.T.red.} -> {eoc} {B.T.blue.}%s :{eoc} ", curr_dir);
			free(cmd);
		}
	}
}*/
int			exec_command(t_shell *shell, char **av)
{
	pid_t	father;

	father = fork();
	if (father > 0)
	{
		wait(&father);
		return (1);
	}
	else if (father == 0)
		execve(shell->cmd, av, NULL);
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
		ft_printf("shell->path[i] apres = {%s}\n", shell->path[i]);
		shell->cmd = shell->path[i];
		ft_printf("shell->input = {%s}\n", shell->input);
		shell->path[i] = ft_strjoin(shell->path[i], shell->input);
		j = ft_strlen(shell->path[i]) - 1;
		while (j >= 0 && shell->path[i][j] == '\n')
			j--;
		shell->path[i][j + 1] = '\0';
		ft_printf("shell->path[%d] = %s\n", i, shell->path[i]);
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
	ft_printf("pas trouve\n");
	return (-1);
}

char		**remove_backslash_n(t_shell *shell)
{
	int		i;

	i = 0;
	while (shell->path[i])
	{
		if (shell->path[i][ft_strlen(shell->path[i]) - 1] == '\n')
			shell->path[i][ft_strlen(shell->path[i]) - 2] = '\0';
		i++;
	}
	ft_printf("je suis passe\n");
	return (shell->path);
}

void		read_input(t_shell *shell, char **av)
{
	char	*curr_dir;
	int		ret;
	int		is_valid;
	int		is_father;

	is_father = 1;
	curr_dir = NULL;
	curr_dir = get_curr_dir(shell->data[6], curr_dir);
	ft_printf("{B.T.red.}-> {eoc} {B.T.blue.}%s :{eoc} ", curr_dir);
	while ((ret = read(0, shell->input, 255)) && is_father == 1)
	{
		shell->path = remove_backslash_n(shell);
		is_valid = check_if_input_valid(shell);
		if (is_valid > -1)
			is_father = exec_command(shell, av);
		if (is_father == 1)
			ft_printf("{B.T.red.}-> {eoc} {B.T.blue.}%s :{eoc} ", curr_dir);
	}
}

int			main(int ac, char **av, char **env)
{
	t_shell	shell;
	int		i;

	i = -1;
	shell.data = NULL;
	shell.data = copy_env_data(shell.data, env);
	shell.path = ft_strsplit(shell.data[12] + 5, ':');
	while (shell.path[++i])
		shell.path[i] = free_strjoin(shell.path[i], "/");
	shell.input = (char*)malloc(sizeof(char) * 255 + 1);
	shell.input[255] = '\0';
	i = 0;
	ac = 0;
	read_input(&shell, av);
	return (0);
}
