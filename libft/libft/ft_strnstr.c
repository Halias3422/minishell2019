/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 12:42:53 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 11:55:19 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	int		b;

	a = 0;
	b = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (a <= len && haystack[a])
	{
		while (haystack[a] == needle[b] && needle[b] && a < len)
		{
			a++;
			b++;
		}
		if (needle[b] == '\0')
			return ((char *)&haystack[a - b]);
		else if (needle[b] != '\0' && b > 0)
		{
			a = a - b;
			b = 0;
		}
		a++;
	}
	return (NULL);
}
