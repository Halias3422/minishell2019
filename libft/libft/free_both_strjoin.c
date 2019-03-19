/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_both_strjoin.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 14:37:42 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/11 14:42:58 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*free_both_strjoin(char *str1, char *str2)
{
	char	*tmp;

	tmp = str1;
	str1 = ft_strjoin(str1, str2);
	free(tmp);
	free(str2);
	return (str1);
}
