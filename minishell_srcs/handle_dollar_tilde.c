/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util_tools2.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/23 10:06:49 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 15:53:54 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char		*fill_entry_with_dollar(char *entry, char *data, char *dol_var,
			int l)
{
	char	*new_entry;
	char	*left;
	int		i;
	int		j;

	i = l;
	new_entry = ft_strnew(l);
	new_entry = free_strjoin(new_entry, data + ft_strlen(dol_var));
	i = l;
	while (entry[i])
		i++;
	left = ft_strnew(i - l);
	j = 0;
	while (i < l)
		left[j++] = entry[i++];
	new_entry = free_strjoin(new_entry, left);
	free(left);
	return (new_entry);
}

char		*dol_var_not_in_env(char *entry, char *dol_var, t_shell *shell)
{
	int		i;

	if (ft_strncmp(entry, "cd", 2) == 0 && ft_strlen(dol_var + 1) >= 1)
	{
		i = 0;
		while (shell->data[i] && ft_strncmp(shell->data[i], "HOME=", 5) != 0)
			i++;
		if (shell->data[i] == NULL)
			ft_printf("HOME not set\n");
		else
			entry = ft_strjoin("cd ", shell->data[i] + 5);
	}
	else
		ft_printf("cd: no such file or directory: %s\n", dol_var);
	return (entry);
}

char		*put_dol_var_in_entry(char *entry, char *dol_var, t_shell *shell,
			int l)
{
	char	*new_entry;
	int		i;
	int		j;

	j = 0;
	i = -1;
	new_entry = ft_strnew(l);
	while (++i < l)
		new_entry[i] = entry[i];
	while (shell->data[j])
	{
		if (ft_strncmp(dol_var + 1, shell->data[j], ft_strlen(dol_var) - 1) == 0
				&& shell->data[j][ft_strlen(dol_var) - 1] == '=')
			break ;
		j++;
	}
	if (shell->data[j] == NULL)
		return (entry = dol_var_not_in_env(entry, dol_var, shell));
//	entry = fill_entry_with_dollar(entry, shell->data[j], dol_var, l);
	new_entry = free_strjoin_2(new_entry, fill_entry_with_dollar(entry,
				shell->data[j], dol_var, l));
	free(entry);
	return (new_entry);
}

char		*get_dollar_content(char *entry, char *dol_var, t_shell *shell
			, int i)
{
	int		j;
	int		l;
	int		k;

	while (entry[++i])
	{
		if (entry[i] == '$')
		{
			k = 0;
			j = i;
			l = i;
			while (entry[j] && entry[j] != 9 && entry[j] != 10 &&
					entry[j] != 32)
				j++;
			dol_var = (char*)malloc(sizeof(char) * (j - i) + 1);
			while (i < j)
				dol_var[k++] = entry[i++];
			dol_var[k] = '\0';
			entry = put_dol_var_in_entry(entry, dol_var, shell, l);
		}
	}
	free(dol_var);
	return (entry);
}

char		*replace_dollar_tilde_var(char *entry, t_shell *shell)
{
	int		i;
	char	*dol_var;

	dol_var = NULL;
	entry = replace_tilde(entry, shell);
	if (ft_strncmp(entry, "echo", 4) != 0)
	{
		i = -1;
		entry = get_dollar_content(entry, dol_var, shell, i);
	}
	return (entry);
}
