/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   modif_env_data.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/22 14:32:38 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/22 15:36:59 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char		**change_data_pwd(char **data, char *path)
{
	free(data[25]);
	data[25] = ft_strjoin("OLD", data[6]);
	free(data[6]);
	data[6] = ft_strjoin("PWD=", path);
	return (data);
}

char		**copy_env_data(char **data, char **env)
{
	int		i;
	int		len;

	data = (char**)malloc(sizeof(char*) * 33 + 1);
	data[33] = NULL;
	i = 0;
	while (env[i])
	{
		len = ft_strlen(env[i]);
		data[i] = (char*)malloc(sizeof(char) * len + 1);
		data[i] = ft_strcpy(data[i], env[i]);
		i++;
	}
	return (data);
}
