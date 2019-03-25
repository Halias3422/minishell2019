/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 09:53:05 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 06:58:20 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void		exiting_minishell(t_shell *shell)
{
	int		i;
	int		j;
	int		k;
	char	*exit_val;

	i = 4;
	k = 0;
	while (shell->entry[i] && (shell->entry[i] == 9 || shell->entry[i] == 10 ||
				shell->entry[i] == 32))
		i++;
	j = i;
	if (shell->entry[i] == '\0')
	{
		exit_free(shell);
		exit(0);
	}
	while (shell->entry[j] && ((shell->entry[j] >= '0' && shell->entry[j] <= '9')
			||( shell->entry[j] == '-')))
		j++;
	exit_val = ft_strnew(j - i);
	while (i < j)
		exit_val[k++] = shell->entry[i++];
	exit_free(shell);
	exit (ft_atoi(exit_val));
}

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
	if (ft_strcmp(shell->entry, "env") == 0 && check++ >= 0)
	{
		while (shell->data[++i])
			ft_printf("%s\n", shell->data[i]);
	}
	else if (ft_strncmp(shell->entry, "echo", 4) == 0)
		check = handle_echo_builtin(shell);
	else if (ft_strncmp(shell->entry, "cd", 2) == 0)
		check = handle_cd_builtin(shell);
	else if (ft_strncmp(shell->entry, "exit", 4) == 0i)
	{
		if (shell->entry[4] == '\0' || shell->entry[4] == 9 || shell->entry[4] == 10 || shell->entry[4] == 32)
			exiting_minishell(shell);
	}
	else if (ft_strncmp(shell->entry, "unsetenv", 8) == 0)
		check = handle_unsetenv_builtin(shell);
	check = check_for_builtins_2(shell, check);
	return (check);
}
