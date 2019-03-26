/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cd_builtin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 13:32:57 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 16:13:45 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			check_forbidden_dir(char *path, t_shell *shell)
{
	char	*forbidden;
	int		i;

	if (access(path, X_OK) == 0 || access(path, F_OK) != 0)
		return (0);
	else
	{
		i = ft_strlen(shell->entry);
		while (i >= 0 && shell->entry[i] != ' ')
			i--;
		forbidden = ft_strnew(ft_strlen(shell->entry) - i - 1);
		forbidden = ft_strcpy(forbidden, shell->entry + i + 1);
		if (ft_strcmp(forbidden, "-") != 0)
			ft_printf("cd: permission denied: %s\n", forbidden);
		else
			ft_printf("cd: permission denied: %s\n", path);
	}
	return (1);
}

char		*cd_is_not_absolute(t_shell *shell, char *path, char *only_path)
{
	path = ft_strjoin("/", path);
	path = free_both_strjoin(get_pwd(shell), path);
	if (access(path, F_OK) == 0)
	{
		if (check_forbidden_dir(path, shell) == 0)
		{
			shell->data = change_data_pwd(shell->data, path, shell);
			chdir(path);
		}
	}
	else if (is_contained_in("$", shell->entry, 0) <= 0 &&
	check_forbidden_dir(path, shell) == 0 && ft_strcmp(only_path, "~") != 0)
		ft_printf("cd: no such file or directory: %s\n", only_path);
	return (path);
}

int			check_path_of_cd(t_shell *shell, char *path)
{
	char	*only_path;

	only_path = ft_strnew(ft_strlen(path));
	only_path = ft_strcpy(only_path, path);
	if (path[0] == '/' && access(path, F_OK) == 0 && ft_strcmp(path, "..") != 0)
	{
		shell->data = change_data_pwd(shell->data, path, shell);
		if (check_forbidden_dir(path, shell) == 0)
			chdir(path);
	}
	else if (ft_strcmp(path, "..") != 0 && ft_strcmp(path, "-") != 0)
	{
		path = cd_is_not_absolute(shell, path, only_path);
		free(path);
	}
	else
		cd_go_previous_folder(shell, path);

	free(only_path);
	return (1);
}

int			handle_cd_builtin(t_shell *shell, int is_builtin, int len)
{
	char	*path;
	int		i;
	int		j;

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
