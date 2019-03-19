/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 13:28:54 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 08:56:51 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		a;

	a = 0;
	if ((unsigned char)dst > (unsigned char)src)
	{
		a = ((int)len - 1);
		while (a >= 0)
		{
			((char*)dst)[a] = ((char*)src)[a];
			a--;
		}
	}
	else
	{
		while (len > 0)
		{
			((char*)dst)[a] = ((char*)src)[a];
			a++;
			len--;
		}
	}
	return (dst);
}
