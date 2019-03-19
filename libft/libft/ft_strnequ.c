/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnequ.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:13:58 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 12:18:22 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	a;

	if (s1 && s2)
	{
		a = 0;
		if (a == n)
			return (1);
		while ((s1[a] && s2[a]) && a < (n - 1) && s1[a] == s2[a])
			a++;
		if (s1[a] != s2[a])
			return (0);
		else
			return (1);
	}
	return (0);
}
