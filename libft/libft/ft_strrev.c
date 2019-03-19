/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strerev.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 14:14:46 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 13:15:43 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_strrev(char *str)
{
	char	*dest;
	int		i;
	size_t	j;

	i = ft_strlen(str) - 1;
	j = 0;
	if (!(dest = (char*)malloc(sizeof(char) * i + 2)))
		return (NULL);
	while (i >= 0)
		dest[j++] = str[i--];
	dest[j] = '\0';
	free(str);
	return (dest);
}
