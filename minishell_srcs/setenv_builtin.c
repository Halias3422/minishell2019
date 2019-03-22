/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   setenv_builtin.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 17:55:01 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 20:19:01 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char			**create_new_entry_env(t_shell *shell, t_setenv *setenv, int k)
{
	char		**new_data;
	int			i;

	i = -1;
	while (shell->data[i])
		i++;
	new_data = (char**)malloc(sizeof(char*) * i + 2);
	i = -1;
	while (shell->data[++i])
	{
		new_data[i] = ft_strnew(ft_strlen(shell->data[i]));
		new_data[i] = ft_strcpy(new_data[i], shell->data[i]);
		free(shell->data[i]);
	}
	free(shell->data);
	new_data[i] = ft_strnew(ft_strlen(setenv->data[k]));
	new_data[i] = ft_strcpy(new_data[i], setenv->data[k]);
	new_data[++i] = NULL;
	return (new_data);
}

void			add_setenv_to_env(t_shell *shell, t_setenv *setenv, int k)
{
	int			i;

	i = 0;
	while (shell->data[i])
	{
		if (ft_strncmp(setenv->var_name, shell->data[i], ft_strlen(
			setenv->var_name)) == 0)
		{
			free(shell->data[i]);
			shell->data[i] = ft_strnew(ft_strlen(setenv->data[k]));
			shell->data[i] = ft_strcpy(shell->data[i], setenv->data[k]);
			break ;
		}
		i++;
	}
	if (shell->data[i] == NULL)
	{
		shell->data = create_new_entry_env(shell, setenv, k);
	}
}

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
		i = 0;
		while (setenv.data[k][i] && setenv.data[k][i] != '=')
			i++;
		setenv.var_name = ft_strnew(i);
		setenv.var_name = ft_strncpy(setenv.var_name, setenv.data[k], i);
		ft_printf("var_name = %s\n", setenv.var_name);
		add_setenv_to_env(shell, &setenv, k);
		k++;
	}

	check = 1;
	return (check);
}
