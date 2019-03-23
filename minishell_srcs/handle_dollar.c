/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util_tools2.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/23 10:06:49 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/23 14:20:17 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char		*put_dol_var_in_entry(char *entry, char *dol_var, t_shell *shell,
			int l)
{
	char	*new_entry;
	char	*left;
	int		i;
	int		j;

	j = 0;
	i = -1;
	new_entry = ft_strnew(l);
	while (++i < l)
		new_entry[i] = entry[i];
	while (shell->data[j] && ft_strncmp(dol_var + 1, shell->data[j],
			ft_strlen(dol_var + 1)) != 0)
		j++;
	if (shell->data[j] == NULL)
	{
		if (ft_strncmp(entry, "cd", 2) == 0)
		{
			i = 0;
			while (shell->data[i] && ft_strncmp(shell->data[i], "HOME=", 5)
					!= 0)
				i++;
			entry = ft_strjoin ("cd ", shell->data[i] + 5);
		}
		return (entry);
	}
	new_entry = free_strjoin(new_entry, shell->data[j] + ft_strlen(dol_var));
	i = l;
	while (entry[i])
		i++;
	left = ft_strnew(i - l);
	j = 0;
	while (i < l)
		left[j++] = entry[i++];
//	left[j] = '\0';
	new_entry = free_strjoin(new_entry, left);
	return (new_entry);
}

char		*put_home_in_entry(char *entry, t_shell *shell, int j, int i)
{
	char	*new_entry;
	int		k;

	k = -1;
	new_entry = ft_strnew(i);
	while (++k < i)
		new_entry[k] = entry[k];
	new_entry = free_strjoin(new_entry, shell->data[j] + 5);
	new_entry = free_strjoin(new_entry, entry + i + 1);
	return (new_entry);
}

char		*replace_tilde(char *entry, t_shell *shell)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (entry[i] && entry[i] != '~')
		i++;
	if (entry[i] == '~')
	{
		while (shell->data[j] && ft_strncmp("HOME=", shell->data[j], 5) != 0)
			j++;
		if (shell->data[j] != NULL)
		{
			entry = put_home_in_entry(entry, shell, j, i);
		}
		else
			ft_printf("HOME not set\n");
	}
	return (entry);
}

char		*replace_dollar_tilde_var(char *entry, t_shell *shell)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*dol_var;

	entry = replace_tilde(entry, shell);
	if (ft_strncmp(entry, "echo", 4) != 0)
	{
	i = -1;
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
	}
	return (entry);
}
