/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cd_builtin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 13:32:57 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 15:44:02 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void		cd_go_previous_folder(t_shell *shell, char *path)
{
	int		i;
	char	*swap;

	if (ft_strcmp(path, "..") == 0)
	{
		i = ft_strlen(shell->data[6]);
		free(shell->data[25]);
		shell->data[25] = ft_strnew(i + 3);
		shell->data[25] = ft_strjoin("OLDPWD=", shell->data[6] + 4);
		while (i >= 0 && shell->data[6][i] != '/')
			i--;
		shell->data[6][i] = '\0';
		path = ft_strjoin("/", path);
		path = ft_strjoin(shell->data[6] + 4, path);
		chdir(path);
	}
	else if (ft_strcmp(path, "-") == 0)
	{
		swap = shell->data[25] + 7;
		shell->data[25] = ft_strjoin("OLD", shell->data[6]);
		shell->data[6] = ft_strjoin("PWD=", swap);
	}
}

int			check_path_of_cd(t_shell *shell, char *path)
{
	char	*only_path;

	only_path = ft_strnew(ft_strlen(path));
	only_path = ft_strcpy(only_path, path);
	if (path[0] == '/' && access(path, F_OK) == 0 && ft_strcmp(path, "..") != 0)
	{
		shell->data = change_data_pwd(shell->data, path);
		chdir(path);
	}
	else if (ft_strcmp(path, "..") != 0 && ft_strcmp(path, "-") != 0)
	{
		path = ft_strjoin("/", path);
		path = ft_strjoin(shell->data[6] + 4, path);
		if (access(path, F_OK) == 0)
		{
			shell->data = change_data_pwd(shell->data, path);
			chdir(path);
		}
		else
			ft_printf("cd: no such file or directory: %s\n", only_path);
	}
	else
		cd_go_previous_folder(shell, path);
	return (1);
}

int			handle_cd_builtin(t_shell *shell)
{
	char	*path;
	int		i;
	int		j;
	int		len;
	int		is_builtin;

	j = 0;
	i = 2;
	while (shell->entry[i] && (shell->entry[i] == 9 || shell->entry[i] == 10 ||
			shell->entry[i] == 32))
		i++;
	len = ft_strlen(shell->entry) - i;
	path = ft_strnew(len);
	while (j < len)
		path[j++] = shell->entry[i++];
	path[j] = '\0';
	if (ft_strcmp(path, ".") != 0)
		is_builtin = check_path_of_cd(shell, path);
	else
		is_builtin = 0;
	return (is_builtin);
}
