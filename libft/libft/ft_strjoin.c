/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:28:58 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/29 15:56:45 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		a;
	int		b;

	if (s1 && s2)
	{
		a = ft_strlen(s1) + ft_strlen(s2);
		b = 0;
		if (!(dest = (char*)malloc(sizeof(char) * (a + 1))))
			return (NULL);
		a = 0;
		while (s1[a])
		{
			dest[a] = s1[a];
			a++;
		}
		while (s2[b])
			dest[a++] = s2[b++];
		dest[a] = '\0';
		return (dest);
	}
	return (0);
}
