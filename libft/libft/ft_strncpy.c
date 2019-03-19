/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 15:15:58 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 15:20:32 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	a;

	a = 0;
	while (src[a] && a < len)
	{
		dst[a] = src[a];
		a++;
	}
	while (a < len)
		dst[a++] = '\0';
	return (dst);
}
