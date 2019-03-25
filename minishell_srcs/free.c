/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 17:13:58 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 07:58:39 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char		**free_db_tab(char **input)
{
	int		i;

	i = 0;
	while (input[i])
		free(input[i++]);
	free(input);
	return (input);
}

void			exit_free(t_shell *shell)
{
	int			i;

	i = 0;
	while (shell->data[i])
		free(shell->data[i++]);
	free(shell->data);
	free(shell->entry);
	i = 0;
while (shell->path[i])
		free(shell->path[i++]);
	free(shell->path);
	i = 0;
//	free(shell->cmd);
}
