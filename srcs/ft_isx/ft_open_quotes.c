/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_open_quotes.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/18 16:42:19 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/20 16:21:29 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	count_quotes(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (s[++i])
		if (s[i] == c && ((i == 0) || (i > 0 && s[i - 1] != '\\')))
			count++;
	return (count % 2);
}

int	ft_open_quotes(char *s, char c)
{
	if (!s || !count_quotes(s, c))
		return (0);
	return (1);
}
