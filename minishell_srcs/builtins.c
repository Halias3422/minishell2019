/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 09:53:05 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 14:38:54 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

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
	return (check);
}
