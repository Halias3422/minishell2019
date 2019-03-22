/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   echo_builtin.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 12:17:19 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 14:31:22 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char		*find_dollar_content(t_shell *shell, int i)
{
	char	*dollar;
	int		l;
	int		k;
	int		j;

	j = i;
	k = 0;
	l = i;
	while (shell->entry[j] && shell->entry[j] != 9 && shell->entry[j] != 10 &&
		shell->entry[j] != 32)
		j++;
	dollar = ft_strnew(j - i + 1);
	while (l < j)
		dollar[k++] = shell->entry[l++];
	dollar[k] = '=';
	return (dollar);
}

int			echo_dollar(t_shell *shell, int i)
{
	char	*dollar;
	int		k;

	dollar = find_dollar_content(shell, i);
	k = 0;
	while (shell->data[k])
	{
		if (ft_strncmp(dollar, shell->data[k], ft_strlen(dollar)) == 0)
		{
			ft_printf("%s\n", shell->data[k]);
			return (i + 1);
		}
		k++;
	}
	while (shell->entry[i] && shell->entry[i] != 9 && shell->entry[i] != 10 &&
			shell->entry[i] != 32)
		i++;
	return (i);
}

int			handle_echo_builtin(t_shell *shell)
{
	int		i;
	int		check;

	check = 0;
	i = 3;
	while (shell->entry[++i])
	{
		if (shell->entry[i] == '$' && check++ >= 0)
			i = echo_dollar(shell , i + 1);
	}
	return (check);
}
