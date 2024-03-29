/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   unsetenv_builtin.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/23 09:17:46 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 09:39:50 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char			**remove_line_from_env(t_shell *shell, int j)
{
	char		**new_data;
	int			i;
	int			k;

	i = 0;
	while (shell->data[i])
		i++;
	new_data = (char**)malloc(sizeof(char*) * i);
	k = -1;
	i = 0;
	while (shell->data[++k])
	{
		if (k != j)
		{
			new_data[i] = ft_strnew(ft_strlen(shell->data[k]));
			new_data[i] = ft_strcpy(new_data[i], shell->data[k]);
			i++;
		}
		free(shell->data[k]);
	}
	free(shell->data);
	new_data[i] = NULL;
	return (new_data);
}

int				find_line_and_remove_in_env(t_setenv *unset, t_shell *shell,
				int i, int j)
{
	if (ft_strncmp(unset->data[i], shell->data[j],
	ft_strlen(unset->data[i])) == 0 && unset->check++ >= 0 &&
	(shell->data[j][ft_strlen(unset->data[i])] + 1 == '=' ||
	shell->data[j][ft_strlen(unset->data[i])] == '='))
	{
		shell->data = remove_line_from_env(shell, j);
		if (ft_strncmp(unset->data[i], "PATH", 4) == 0)
			shell->path = fill_shell_path(shell);
	}
	j++;
	return (j);
}

void			remove_unset_to_env(t_shell *shell, t_setenv *unset)
{
	int			i;
	int			j;
	int			tab_len;

	unset->check = 0;
	i = 0;
	while (unset->data[i])
	{
		tab_len = 0;
		while (shell->data[tab_len])
			tab_len++;
		j = 0;
		while (shell->data[j] && j < tab_len)
			j = find_line_and_remove_in_env(unset, shell, i, j);
		if (unset->check == 0)
			ft_printf("unsetenv: no environment variable named: %s\n",
			unset->data[i]);
		i++;
	}
}

int				handle_unsetenv_builtin(t_shell *shell)
{
	int			check;
	t_setenv	unset;
	int			i;

	i = 8;
	while (shell->entry[i] && (shell->entry[i] == 9 || shell->entry[i] == 10 ||
		shell->entry[i] == 32))
		i++;
	unset.data = ft_strsplit(shell->entry + i, ' ');
	remove_unset_to_env(shell, &unset);
	check = 1;
	unset.data = free_db_tab(unset.data);
	return (check);
}
