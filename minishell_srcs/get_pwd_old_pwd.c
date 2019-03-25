/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_pwd_old_pwd.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/25 09:40:59 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 09:41:26 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			get_pwd_int(t_shell *shell)
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

char		*get_pwd(void)
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
