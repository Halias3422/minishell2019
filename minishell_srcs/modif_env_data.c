/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   modif_env_data.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 14:32:38 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 16:17:23 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char		**fill_shell_path(t_shell *shell)
{
	int		i;
	int		path;

	path = 0;
	while (shell->data[path] && ft_strncmp("PATH=", shell->data[path], 5) != 0)
		path++;
	if (shell->data[path] == NULL)
	{
		i = -1;
		while (shell->path[++i])
			shell->path[i][0] = '\0';
		return (shell->path);
	}
	i = -1;
	shell->path = free_db_tab(shell->path);
	shell->path = ft_strsplit(shell->data[path] + 5, ':');
	while (shell->path[++i])
		shell->path[i] = free_strjoin(shell->path[i], "/");
	return (shell->path);
}

char		**add_pwd_data(char **data, int usage)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = -1;
	tmp = NULL;
	tmp = copy_env_data(tmp, data);
	while (tmp[i])
		i++;
	data = free_db_tab(data);
	data = (char**)malloc(sizeof(char*) * 255);
	data[i + 1] = NULL;
	while (tmp[++j])
	{
		data[j] = ft_strnew(ft_strlen(tmp[j]));
		data[j] = ft_strcpy(data[j], tmp[j]);
	}
	if (usage == 1)
		data[i] = free_strjoin_2("PWD=", get_pwd());
	else if (usage == 2)
		data[i] = free_strjoin_2("OLDPWD=", get_pwd());
	free_db_tab(tmp);
	return (data);
}

char		**change_data_pwd(char **data, char *path, t_shell *shell)
{
	int		old_pwd;
	int		pwd;
	char	*join_pwd;

	pwd = get_pwd_int(shell);
	old_pwd = get_old_pwd_int(shell);
	if (pwd > -1 && old_pwd > -1)
	{
		join_pwd = get_pwd(shell);
		free(data[old_pwd]);
		data[old_pwd] = ft_strjoin("OLDPWD=", join_pwd);
		free(data[pwd]);
		free(join_pwd);
		data[pwd] = ft_strjoin("PWD=", path);
	}
	if (pwd == -1)
		data = add_pwd_data(data, 1);
	if (old_pwd == -1)
		data = add_pwd_data(data, 2);
	return (data);
}

int			find_path(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char		**copy_env_data(char **data, char **env)
{
	int		i;
	int		len;
	int		env_len;

	env_len = 0;
	while (env[env_len])
		env_len++;
	data = (char**)malloc(sizeof(char*) * env_len + 8);
	data[env_len] = NULL;
	i = 0;
	while (i < env_len)
	{
		len = ft_strlen(env[i]);
		data[i] = (char*)malloc(sizeof(char) * len + 1);
		data[i] = ft_strcpy(data[i], env[i]);
		i++;
	}
	return (data);
}
