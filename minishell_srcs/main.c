/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 09:47:42 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 15:39:16 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			main(int ac, char **av, char **env)
{
	t_shell	shell;
	int		i;

	av = NULL;
	i = -1;
	shell.data = copy_env_data(shell.data, env);
	if (env[0] != NULL)
	{
		shell.path = ft_strsplit(shell.data[find_path(env)] + 5, ':');
		while (shell.path[++i])
			shell.path[i] = free_strjoin(shell.path[i], "/");
	}
	else
	{
		shell.path = (char**)malloc(sizeof(char*) * 1);
		shell.path[0] = NULL;
	}
	shell.entry = ft_strnew(255);
	shell.curr_dir = NULL;
	i = 0;
	ac = 0;
	read_input(&shell);
	return (0);
}
