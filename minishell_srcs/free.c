/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 17:13:58 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 17:21:32 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void			exit_free(t_shell *shell)
{
	int			i;

	i = 0;
	free(shell->curr_dir);
	while (shell->data[i])
		free(shell->data[i++]);
	free(shell->data);
	free(shell->entry);
	i = 0;
	free(shell->cmd);
}
