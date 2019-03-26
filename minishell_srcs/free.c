/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 17:13:58 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 13:53:56 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char			**free_db_tab(char **input)
{
	int			i;

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
	shell->data = free_db_tab(shell->data);
	free(shell->entry);
	i = 0;
	while (shell->path[i])
		free(shell->path[i++]);
	free(shell->path);
	i = 0;
}
