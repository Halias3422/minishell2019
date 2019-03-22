/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 09:53:05 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 18:37:55 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			check_for_builtins_2(t_shell *shell, int check)
{
	int		i;

	i = -1;
	if (ft_strcmp(shell->entry, "setenv") == 0)
	{
		while (shell->data[++i])
			ft_printf("%s\n", shell->data[i]);
	}
	else if (ft_strncmp(shell->entry, "setenv", 6) == 0)
		check = handle_setenv_builtin(shell);
	return (check);
}

int			check_for_builtins(t_shell *shell)
{
	int		i;
	int		check;

	check = 0;
	i = -1;
	if (ft_strcmp(shell->entry, "env") == 0)
	{
		while (shell->data[++i])
			ft_printf("%s\n", shell->data[i]);
	}
	else if (ft_strncmp(shell->entry, "echo", 4) == 0)
		check = handle_echo_builtin(shell);
	else if (ft_strncmp(shell->entry, "cd", 2) == 0)
		check = handle_cd_builtin(shell);
	else if (ft_strncmp(shell->entry, "exit", 4) == 0)
	{
//		exit_free(shell);
		exit(0);
	}
	check = check_for_builtins_2(shell, check);
	return (check);
}
