/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_range.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 11:14:52 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 08:56:19 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int		a;
	int		b;
	int		*tab;

	if (min >= max)
		return (0);
	a = max - min;
	b = 0;
	if (!(tab = (int*)malloc(sizeof(int) * a)))
		return (0);
	while (b < a)
	{
		tab[b] = min;
		b++;
		min++;
	}
	return (tab);
}
