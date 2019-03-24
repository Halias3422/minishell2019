/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   modif_env_data.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 14:32:38 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/24 09:07:48 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char		**change_data_pwd(char **data, char *path, t_shell *shell)
{
	int		old_pwd;
	int		pwd;

	pwd = get_pwd_int(shell);
	old_pwd = get_old_pwd_int(shell);
	free(data[old_pwd]);
	data[old_pwd] = ft_strjoin("OLD", get_pwd(shell));
	free(data[pwd]);
	data[pwd] = ft_strjoin("PWD=", path);
	return (data);
}

char		**copy_env_data(char **data, char **env)
{
	int		i;
	int		len;

	data = (char**)malloc(sizeof(char*) * 34 + 1);
	data[33] = NULL;
	i = 0;
	while (i < 33)
	{
		len = ft_strlen(env[i]);
		data[i] = (char*)malloc(sizeof(char) * len + 1);
		data[i] = ft_strcpy(data[i], env[i]);
		i++;
	}
	return (data);
}
