/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 09:47:42 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/23 12:17:37 by vde-sain    ###    #+. /#+    ###.fr     */
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
	shell.data = NULL;
	shell.data = copy_env_data(shell.data, env);
	shell.path = ft_strsplit(shell.data[12] + 5, ':');
	while (shell.path[++i])
		shell.path[i] = free_strjoin(shell.path[i], "/");
	shell.entry = ft_strnew(255);
	i = 0;
	ac = 0;
	read_input(&shell);
	return (0);
}
