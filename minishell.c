/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 13:34:38 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 08:09:42 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int			main(int ac, char **av, char **env)
{
//	pid_t	father;
//	char	*cmd;
	int		i;
	int		ret;
	char	*input;

	input = (char*)malloc(sizeof(char) * 255 + 1);
	input[255] = '\0';
	av = NULL;
	i = 1;
	ac = 0;
//	cmd = (char*)malloc(sizeof(char) * 5 + 1);
//	cmd = "/bin/";
//	father = fork();
//	cmd = ft_strjoin(cmd, av[1]);
	while ((ret = read(0, input, 255)))
	{
		ft_printf("input = %s\n", input);
		if (ft_strncmp(input, "env", 3) == 0)
				ft_printf("%T\n", env);
		if (ft_strncmp(input, "exit", 4) == 0)
			exit(0);
	}
	/*
	if (father > 0)
	{
		wait(&father);
		if (ft_strcmp(cmd, "/bin/exit") == 0)
		{
			ft_printf("exiting\n");
			exit(0);
		}
		printf("I M YOUR FATHER\n");
	}
	if (father == 0)
	{
		execve(cmd,++av,NULL);
	}*/
	return (0);
}
