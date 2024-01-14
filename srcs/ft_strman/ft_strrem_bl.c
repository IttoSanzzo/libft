/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strrem_bl.c                                     :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/12 00:56:42 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/14 12:37:31 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	strbllen(char *str)
{
	int	len;
	int	bl;
	int	i;

	len = 0;
	bl = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\\' && !bl)
		{
			bl = 1;
			continue ;
		}
		if ((str[i] != '\\')
			|| (str[i] == '\\' && bl))
			len++;
		bl = 0;
	}
	return (len);
}

void	ft_strrem_bl(char **str)
{
	int		bl;
	int		i;
	int		y;
	char	*new;

	if (!str || !*str)
		return ;
	new = (char *)ft_calloc(strbllen(*str) + 1, sizeof(char));
	bl = 0;
	i = -1;
	y = -1;
	while (str[0][++i])
	{
		if (str[0][i] == '\\' && !bl)
		{
			bl = 1;
			continue ;
		}
		if ((str[0][i] != '\\')
			|| (str[0][i] == '\\' && bl))
			new[++y] = str[0][i];
		bl = 0;
	}
	ft_nfreestr(str);
	*str = new;
}
