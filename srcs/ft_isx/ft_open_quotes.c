/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_open_quotes.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/18 16:42:19 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/20 14:08:08 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */
/*
#include "libft.h"

static int	ft_is_close(char *s, char c)
{
	return ((s[0] != '\\' && s[1] == c && (s[2] == ' ' || s[2] == '\0')));
}

static int	search_closure(char *s, char c)
{
	int	i;

	i = 0;
	while (s[++i])
		if (s[i] == c && !(i > 0 && s[i - 1] == '\\')
			&& (s[i + 1] == ' ' || s[i + 1] == '\0'))
			return (i);
	return (-1);
}

int	ft_open_quotes(char *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	while (s[++i])
		if (s[i] == c && !(i > 0 && s[i - 1] == '\\'))
			count++;
	if (count % 2 != 0)
		return (1);
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
		{
			i = search_closure((char *)(s + i), c);
			if (i == -1)
				return (1);
		}
	}
	return (0);
}*/
