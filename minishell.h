/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/19 13:35:26 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 14:32:53 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include <dirent.h>

typedef struct		s_shell
{
	char			**data;
	char			**path;
	char			*input;
	char			*cmd;
}					t_shell;

#endif
