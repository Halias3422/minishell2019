/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 11:37:24 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 13:00:21 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = 0;
	c = 0;
	while (dst[a] && a < size)
		a++;
	b = a;
	while (src[c] && ((b + c) + 1) < size)
		dst[a++] = src[c++];
	if (b < size)
		dst[a] = '\0';
	return (b + ft_strlen(src));
}
