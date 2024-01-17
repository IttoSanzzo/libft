/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 20:40:28 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/17 01:39:09 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	wc_s(char **s, char c)
{
	int	wcount;
	int	i;

	i = -1;
	wcount = 0;
	while (s[0][++i])
	{
		if (s[0][i] == c)
			s[0][i] = '\0';
		else if (s[0][i])
			wcount++;
	}
	return (wcount);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	int		i;
	int		y;
	char	*temp;
	char	**tab;

	if (!s)
		return (NULL);
	temp = ft_strdup(s);
	len = wc_s(&temp, c);
	tab = (char **)ft_calloc(len + 1, sizeof(char *));
	y = -1;
	i = 0;
	while (temp[i] == '\0' && len > 0)
		i++;
	while (tab && ++y < len)
	{
		tab[y] = ft_strdup((char *)(temp + i));
		while (temp[i])
			i++;
		while (!temp[i] && y < len - 1)
			i++;
	}
	ft_nfreestr(&temp);
	return (tab);
}
