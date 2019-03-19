/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 13:42:31 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 08:56:59 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n && ((unsigned char*)s1)[a] == ((unsigned char*)s2)[a])
		a++;
	if (a == n)
		return (0);
	return (((unsigned char*)s1)[a] - ((unsigned char*)s2)[a]);
}
