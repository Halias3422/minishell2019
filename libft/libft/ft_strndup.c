/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 16:51:51 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 17:06:59 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*dest;
	size_t	a;

	a = 0;
	if ((int)n < 0)
		n = ft_strlen(s1);
	if (!(dest = (char*)malloc(sizeof(*s1) * (n + 1))))
		return (NULL);
	while (s1[a] && a < n)
	{
		dest[a] = s1[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
