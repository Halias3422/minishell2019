/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 18:02:53 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 12:05:04 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[a])
	{
		while (haystack[a] == needle[b] && needle[b])
		{
			a++;
			b++;
		}
		if (needle[b] == '\0')
			return ((char *)&haystack[a - b]);
		else if (needle[b] != '\0' && b > 0)
		{
			a = a - (b - 1);
			b = 0;
		}
		a++;
	}
	return (NULL);
}
