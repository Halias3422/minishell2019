/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:19:08 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 12:10:52 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	a;
	char			*dest;

	a = 0;
	if (s)
	{
		if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (a < len)
			dest[a++] = s[start++];
		dest[a] = '\0';
		return (dest);
	}
	return (NULL);
}
