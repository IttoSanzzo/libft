/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_open_quotes.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/18 16:42:19 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/18 17:02:27 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	search_closure(char *s, char c)
{
	int	i;

	i = 0;
	while (s[++i])
		if (s[i] == c && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			return (i);
	return (-1);
}

int	ft_open_quotes(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		i++;
		if (s[i] == c)
		{
			i = search_closure((char *)(s + i), c);
			if (i == -1)
				return (1);
		}
	}
	return (0);
}
