/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strrem_q.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/12 00:56:42 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/12 01:59:23 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	strqlen(char *str)
{
	int	open;
	int	len;
	int	i;

	open = 0;
	len = 0;
	i = -1;
	while (str[++i])
	{
		ft_squotes(str, &open, i);
		if ((str[i] != '\"' && str[i] != '\'')
			|| (open == 1 && str[i] == '\"')
			|| (open == 2 && str[i] == '\'')
			|| (i > 0 && (str[i - 1] == '\\')))
			len++;
	}
	return (len);
}

void	ft_strrem_q(char **str)
{
	int		open;
	int		i;
	int		y;
	char	*new;

	if (!str || !*str)
		return ;
	new = (char *)ft_calloc(strqlen(*str) + 1, sizeof(char));
	open = 0;
	i = -1;
	y = -1;
	while (str[0][++i])
	{
		ft_squotes(*str, &open, i);
		if ((str[0][i] != '\"' && str[0][i] != '\'')
			|| (open == 1 && str[0][i] == '\"')
			|| (open == 2 && str[0][i] == '\'')
			|| (i > 0 && (str[0][i - 1] == '\\')))
			new[++y] = str[0][i];
	}
	ft_nfreestr(str);
	*str = new;
}
