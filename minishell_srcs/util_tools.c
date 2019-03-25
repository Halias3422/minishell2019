/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util_tools.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 09:45:43 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 08:25:33 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		get_pwd_int(t_shell *shell)
{
	int		i;

	i = 0;
	while (shell->data[i])
	{
		if (ft_strncmp(shell->data[i], "PWD=", 4) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char		*get_pwd()
{
	char	*pwd;
	char	*buf;
	char	*new_pwd;
	
	buf = NULL;
	pwd = getcwd(buf, 4096);
	new_pwd = ft_strnew(ft_strlen(pwd));
	new_pwd = ft_strcpy(new_pwd, pwd);
	free(pwd);
	free(buf);
	return (new_pwd);

}

int			get_old_pwd_int(t_shell *shell)
{
	int		i;

	i = 0;
	while (shell->data[i])
	{
		if (ft_strncmp(shell->data[i], "OLDPWD=", 7) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char		*get_curr_dir(char *curr_dir)
{
	int		i;
	char	*buf;
	char	*new_curr_dir;

	buf = NULL;
	curr_dir = getcwd(buf, 4096);
	i = ft_strlen(curr_dir);
	while (i >= 0 && curr_dir[i] != '/')
		i--;
	new_curr_dir = ft_strnew(i);
	new_curr_dir = ft_strcpy(new_curr_dir, curr_dir + i + 1);
	free(curr_dir);
	free(buf);
	return (new_curr_dir);
}

char		**remove_first_backslash_n(t_shell *shell)
{
	int		i;
	int		j;

	i = 0;
	while (shell->path != NULL && shell->path[i])
	{
		j = 0;
		while (shell->path[i][j])
		{
			if (shell->path[i][j] == '\n')
				shell->path[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (shell->path);
}

char		*clean_entry(t_shell *shell)
{
	int		i;
	int		j;
	int		k;
	char	*new_entry;

	k = 0;
	i = 0;
	while (shell->entry[i] && (shell->entry[i] == 9 || shell->entry[i] == 10 ||
			shell->entry[i] == 32))
		i++;
	j = ft_strlen(shell->entry) - 1;
	while (j >= 0 && (shell->entry[j] == '\n' || shell->entry[j] == ' '))
		j--;
	new_entry = (char*)malloc(sizeof(char) * (ft_strlen(shell->entry) - i) + 1);
	while (i <= j)
		new_entry[k++] = shell->entry[i++];
	new_entry[k] = '\0';
	k = 0;
	while (new_entry[k++])
	{
		if (new_entry[k] == '\n')
			new_entry[k] = '\0';
	}
	free(shell->entry);
	return (new_entry);
}
