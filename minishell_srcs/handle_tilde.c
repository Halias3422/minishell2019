/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_tilde.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/25 14:56:16 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 13:51:54 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char		*put_home_in_entry(char *entry, t_shell *shell, int j, int i)
{
	char	*new_entry;
	int		k;

	k = -1;
	new_entry = ft_strnew(i);
	while (++k < i)
		new_entry[k] = entry[k];
	new_entry = free_strjoin(new_entry, shell->data[j] + 5);
	if ((int)ft_strlen(entry) >= i + 1)
	new_entry = free_strjoin(new_entry, entry + i + 1);
	return (new_entry);
}

char		*no_word_after_tilde(char *entry, t_shell *shell, int i, int j)
{
	if (entry[i] == '~' && (!entry[i + 1] || entry[i + 1] == 9 || entry[i + 1]
		== 10 || entry[i + 1] == 32))
	{
		if (shell->data[j] != NULL)
			entry = put_home_in_entry(entry, shell, j, i);
		else
			ft_printf("HOME not set\n");
	}
	return (entry);
}

char		*replace_tilde(char *entry, t_shell *shell)
{
	int		i;
	int		j;
	char	*after_tilde;

	j = 0;
	i = 0;
	while (shell->data[j] && ft_strncmp("HOME=", shell->data[j], 5) != 0)
		j++;
	while (entry[i] && entry[i] != '~')
		i++;
	entry = no_word_after_tilde(entry, shell, i, j);
	if (entry[i] == '~' && entry[i + 1] && entry[i + 1] != 9 && entry[i + 1]
	!= 10 && entry[i + 1] != 32)
	{
		after_tilde = ft_strnew(ft_strlen(entry) - i - 1);
		after_tilde = ft_strcpy(after_tilde, entry + i + 1);
		if (shell->data[j] != NULL)
			entry = put_home_in_entry(entry, shell, j, i);
		i = ft_strlen(entry);
		while (i - 1 >= 0 && entry[i - 1] != '/')
			i--;
		entry[i] = '\0';
		entry = free_strjoin(entry, after_tilde);
	}
	return (entry);
}
