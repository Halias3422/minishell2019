/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtim.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:39:19 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 18:30:11 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int a, int b)
{
	if (b > 0)
		return (b - a);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*dest;
	int		a;
	int		b;
	int		c;
	int		z;

	if (s)
	{
		a = 0;
		b = ft_strlen(s) - 1;
		c = 0;
		while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
			a++;
		while (s[b] == ' ' || s[b] == '\n' || s[b] == '\t')
			b--;
		if (!(dest = (char*)malloc(sizeof(*dest) * (ft_size(a, b) + 2))))
			return (NULL);
		z = b - a;
		while (c <= z)
			dest[c++] = s[a++];
		dest[c] = '\0';
		return (dest);
	}
	return (NULL);
}
