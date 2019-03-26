/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cd_go_back.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 10:58:10 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 13:57:08 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char		*cd_is_two_points(t_shell *shell, char *path)
{
	char	*pwd_data;
	int		old_pwd;
	int		i;

	pwd_data = get_pwd();
	old_pwd = get_old_pwd_int(shell);
	i = ft_strlen(pwd_data);
	if (old_pwd > -1)
		free(shell->data[old_pwd]);
	shell->data[old_pwd] = ft_strjoin("OLDPWD=", pwd_data);
	path = ft_strjoin("/", path);
	path = free_strjoin_2(pwd_data, path);
	if (check_forbidden_dir(path, shell) == 0)
		chdir(path);
	free(path);
	while (i >= 0 && shell->data[get_pwd_int(shell)][i] != '/')
		i--;
	shell->data[get_pwd_int(shell)][i] = '\0';
	free(pwd_data);
	return (path);
}

void		cd_go_previous_folder(t_shell *shell, char *path)
{
	int		i;
	char	*swap;
	int		old_pwd;
	char	*pwd_data;

	old_pwd = get_old_pwd_int(shell);
	if (old_pwd == -1 || get_pwd_int(shell) == -1)
		shell->data = change_data_pwd(shell->data, path, shell);
	pwd_data = get_pwd();
	if (ft_strcmp(path, "..") == 0)
		path = cd_is_two_points(shell, path);
	else if (ft_strcmp(path, "-") == 0 && old_pwd > -1 && check_forbidden_dir(
			shell->data[old_pwd] + 7, shell) == 0)
	{
		i = get_pwd_int(shell);
		swap = ft_strnew(ft_strlen(shell->data[old_pwd]) - 7);
		swap = ft_strcpy(swap, shell->data[old_pwd] + 7);
		free(shell->data[old_pwd]);
		shell->data[old_pwd] = ft_strjoin("OLD", pwd_data);
		free(shell->data[i]);
		shell->data[i] = ft_strjoin("PWD=", swap);
		free(swap);
		chdir(shell->data[i] + 4);
	}
	free(pwd_data);
}
