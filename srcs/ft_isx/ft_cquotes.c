/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_cquotes.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/18 16:42:19 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/09 00:52:12 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

int	ft_cquotes(char *s)
{
	int	i;
	int	open;

	i = -1;
	open = 0;
	if (!s)
		return (0);
	while (s[++i])
	{
		if (i > 0 && s[i - 1] == '\\')
			continue ;
		else if (open == 0 && s[i] == '\"')
			open = 2;
		else if (open == 0 && s[i] == '\'')
			open = 1;
		else if (open == 2 && s[i] == '\"')
			open = 0;
		else if (open == 1 && s[i] == '\'')
			open = 0;
	}
	return (open);
}
