/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   chek_content.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 14:14:41 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/11 14:23:49 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			check_content_equal(char *source, char *cmp)
{
	int		i;
	int		j;

	j = 0;
	while (cmp[j])
	{
		i = 0;
		while (source[i] && cmp[j] != source[i])
			i++;
		if (!source[i])
			return (cmp[j]);
		j++;
	}
	return (0);
}
