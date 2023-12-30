/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_cquotes.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/18 16:42:19 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/30 00:29:54 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

int	ft_cquotes(char *s)
{
	int		closed;
	int		i;
	char	c;

	if (!s)
		return (0);
	closed = 1;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '\\' && s[i + 1])
		{
			i++;
			continue ;
		}
		if (closed && (s[i] == '\"' || s[i] == '\''))
		{
			closed--;
			c = (char)s[i];
		}
		else if (!closed && s[i] == c)
			closed++;
	}
	return (closed);
}
