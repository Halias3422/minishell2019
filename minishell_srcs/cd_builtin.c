/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cd_builtin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 13:32:57 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/23 14:15:22 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void		cd_go_previous_folder(t_shell *shell, char *path)
{
	int		i;
	char	*swap;
	char	*tmp;
	int		old_pwd;

	old_pwd = get_old_pwd_int(shell);
	if (ft_strcmp(path, "..") == 0)
	{
		i = ft_strlen(get_pwd(shell));
		free(shell->data[old_pwd]);
		shell->data[old_pwd] = ft_strnew(i + 3);
		shell->data[old_pwd] = ft_strjoin("OLDPWD=", get_pwd(shell) + 4);
		tmp = path;
		path = ft_strjoin("/", path);
//		free(tmp);
		path = ft_strjoin(get_pwd(shell) + 4, path);
		chdir(path);
//		free(path);
		while (i >= 0 && shell->data[get_pwd_int(shell)][i] != '/')
			i--;
		shell->data[get_pwd_int(shell)][i] = '\0';

	}
	else if (ft_strcmp(path, "-") == 0)
	{
		swap = shell->data[old_pwd] + 7;
		shell->data[old_pwd] = ft_strjoin("OLD", get_pwd(shell));
		shell->data[get_pwd_int(shell)] = ft_strjoin("PWD=", swap);
	}
}

int			check_path_of_cd(t_shell *shell, char *path)
{
	char	*only_path;

	only_path = ft_strnew(ft_strlen(path));
	only_path = ft_strcpy(only_path, path);
	if (path[0] == '/' && access(path, F_OK) == 0 && ft_strcmp(path, "..") != 0)
	{
		shell->data = change_data_pwd(shell->data, path, shell);
		chdir(path);
	}
	else if (ft_strcmp(path, "..") != 0 && ft_strcmp(path, "-") != 0)
	{
		path = ft_strjoin("/", path);
		path = ft_strjoin(get_pwd(shell) + 4, path);
		if (access(path, F_OK) == 0)
		{
			shell->data = change_data_pwd(shell->data, path, shell);
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
	i = 0;
	while (shell->data[i] && ft_strncmp(shell->data[i], "HOME=", 5) != 0)
		i++;
	if (ft_strlen(path) == 0 && shell->data[i] != NULL)
		path = put_home_in_entry(path, shell, i, 0);
	if (ft_strcmp(path, ".") != 0)
		is_builtin = check_path_of_cd(shell, path);
	else
		is_builtin = 0;
	free(path);
	return (is_builtin);
}
