/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 10:01:44 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 13:09:45 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *s, char c)
{
	int			a;
	int			b;
	int			verif;

	a = 0;
	b = 0;
	verif = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[a])
	{
		if (s[a] != c && verif == 0)
		{
			b++;
			verif = 1;
		}
		if (s[a] == c && verif == 1)
			verif = 0;
		a++;
	}
	return (b);
}

static char		**ft_sort_words(int nb, char **tab, char const *s, char c)
{
	int			a;
	int			b;
	int			z;
	int			j;

	a = 0;
	z = 0;
	j = 0;
	while (j < nb)
	{
		while (s[a] == c)
			a++;
		b = a;
		while (s[b] != c && s[b])
			b++;
		if (!(tab[j] = (char*)malloc(sizeof(char) * (b - a) + 1)))
			return (NULL);
		while (a < b)
			tab[j][z++] = s[a++];
		tab[j++][z] = '\0';
		z = 0;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int			nb;
	char		**tab;

	if (s)
	{
		nb = ft_count_words(s, c);
		if (!(tab = (char**)malloc(sizeof(char*) * (nb + 1))))
			return (NULL);
		tab[nb] = NULL;
		if (nb == 0)
			return (tab);
		return (ft_sort_words(nb, tab, s, c));
	}
	return (NULL);
}
