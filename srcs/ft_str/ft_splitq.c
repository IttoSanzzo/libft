/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_splitq.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 20:40:28 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/26 01:13:40 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	wc_q(char const *s, char c)
{
	int	wcount;
	int	open;
	int	flag;
	int	i;

	open = -1;
	i = -1;
	flag = 1;
	wcount = 0;
	while (s[++i])
	{
		if (s[i] == c && !(i > 0 && s[i - 1] == '\\'))
			open = -open;
		if (s[i] == ' ' && open == -1)
			flag = 1;
		else if (s[i] && flag == 1 && ++wcount)
			flag = 0;
	}
	return (wcount);
}

static int	wlq(char const *s, char c)
{
	int	wlen;
	int	open;
	int	i;

	open = -1;
	i = -1;
	wlen = 0;
	while (s[++i])
	{
		if (s[i] == '\\' || s[i] == c)
		{
			if (s[i] == '\\' && s[++i])
				wlen++;
			if (s[i] == c)
				open = -open;
			if (s[i])
				continue ;
		}
		if ((s[i] == ' ' && open == -1) || s[i] == '\0')
			break ;
		wlen++;
	}
	return (wlen);
}

static char	*next_quote_q(char const *s, int *i, char c, char **tab)
{
	int		open;
	int		p;
	char	*quote;

	quote = (char *)ft_calloc(wlq((char *)(s + (*i)--), c) + 1, sizeof(char));
	if (!quote)
		return ((char *)ft_freetab(tab));
	open = -1;
	p = -1;
	while (s[++(*i)])
	{
		if (s[*i] == '\\' || s[*i] == c)
		{
			if (s[*i] == '\\' && s[++(*i)])
				quote[++p] = s[*i];
			if (s[*i] == c)
				open = -open;
			if (s[*i])
				continue ;
		}
		if ((s[*i] == ' ' && open == -1) || s[*i] == '\0')
			break ;
		quote[++p] = s[*i];
	}
	return (quote);
}

char	**ft_splitq(char const *s, char c)
{
	int		i;
	int		wc;
	int		y;
	char	**tab;

	if (!s)
		return (NULL);
	wc = wc_q(s, c);
	tab = (char **)ft_calloc(wc + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	y = -1;
	while (s[i] && ++y < wc)
	{
		while (s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		tab[y] = next_quote_q(s, &i, c, tab);
		if (!tab)
			return (NULL);
	}
	return (tab);
}
