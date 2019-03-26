/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_strjoin_2.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/24 10:26:23 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 11:06:20 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*free_strjoin_2(char *str1, char *str2)
{
	char	*tmp;

	tmp = str2;
	str1 = ft_strjoin(str1, str2);
	free(tmp);
	return (str1);
}
