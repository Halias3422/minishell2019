/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   setenv_builtin.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 17:55:01 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 18:32:01 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int				handle_setenv_builtin(t_shell *shell)
{
	int			check;
	t_setenv	setenv;
	int			i;
	int			k;

	i = 6;
	k = 0;
	while (shell->entry[i] && (shell->entry[i] == 9 || shell->entry[i] == 10 ||
		shell->entry[i] == 32))
		i++;
	setenv.data = ft_strsplit(shell->entry + i, ' ');
	while (setenv.data[k])
	{
		ft_printf("setenv[%d] = {%s}\n", k, setenv.data[k]);
		k++;
	}

	/*
	j = i;
	while (shell->entry[j] && shell->entry[j] != 61 && shell->entry[j] != 9 &&
		shell->entry[j] != 10 && shell->entry[j] != 32)
		j++;
	setenv->data = ft_strnew(j - i);
	while (i < j)
		setenv->data[k++] = shell->entry[i++];
	setenv->data[k] = '\0';*/
	check = 1;
	return (check);
}
