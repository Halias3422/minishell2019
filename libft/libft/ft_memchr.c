/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 13:35:24 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 08:57:01 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		a;

	a = 0;
	while (n > 0)
	{
		if (((unsigned char*)s)[a] == (unsigned char)c)
			return ((char*)&s[a]);
		a++;
		n--;
	}
	return (NULL);
}
