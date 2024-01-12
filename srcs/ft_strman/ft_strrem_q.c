/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strrem_q.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/12 00:56:42 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/12 01:17:14 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	strqlen(char *str)
{
	int	open;
	int	len;
	int	i;

	len = 0;
	i = -1;
	while (str[++i])
	{
		open = 0;
		ft_squotes(str, &open, i);
		if (open == 0)
			len++;
	}
	return (len);
}

void	ft_strrem_q(char **str)
{
	int	open;
	int	i;
	int	y;
	char	*new;

	if (!str || !*str)
		return ;
	new = (char *)ft_calloc(strqlen(*str) + 1, sizeof(char));
	i = -1;
	y = -1;
	while (str[0][++i])
	{
		open = 0;
		ft_squotes(*str, &open, i);
		if (open == 0)
			new[++y] = str[0][i];
	}
	ft_nfreestr(str);
	*str = new;
}
