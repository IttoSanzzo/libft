/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strrem_bl.c                                     :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/12 00:56:42 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/14 12:22:27 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	strbllen(char *str)
{
	int	open;
	int	len;
	int	i;

	open = 0;
	len = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\\' && !open)
			open = 1;
		if ((str[i] != '\\')
			|| (str[i] == '\\' && open))
			len++;
		open = 0;
	}
	return (len);
}

void	ft_strrem_bl(char **str)
{
	int		open;
	int		i;
	int		y;
	char	*new;

	if (!str || !*str)
		return ;
	new = (char *)ft_calloc(strbllen(*str) + 1, sizeof(char));
	open = 0;
	i = -1;
	y = -1;
	while (str[0][++i])
	{
		if (str[0][i] == '\\' && !open)
			open = 1;
		if ((str[0][i] != '\\')
			|| (str[0][i] == '\\' && open))
			new[++y] = str[0][i];
		open = 0;
	}
	ft_nfreestr(str);
	*str = new;
}
