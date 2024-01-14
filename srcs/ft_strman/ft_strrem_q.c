/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strrem_q.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/12 00:56:42 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/14 13:08:00 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	qsquotes(char *line, int *open, int i, int *bl)
{
	if (line[i] == '\\' && !*bl)
	{
		*bl = 1;
		return (3);
	}
	if (*bl)
		return (0);
	else if (line[i] == '\"' || line[i] == '\'')
	{
		if (*open == 0 && line[i] == '\"')
			*open = 2;
		else if (*open == 0 && line[i] == '\'')
			*open = 1;
		else if (*open == 2 && line[i] == '\"')
			*open = 0;
		else if (*open == 1 && line[i] == '\'')
			*open = 0;
		return (1);
	}
	return (0);
}

static int	strqlen(char *str)
{
	int	open;
	int	len;
	int	bl;
	int	i;

	open = 0;
	len = 0;
	bl = 0;
	i = -1;
	while (str[++i])
	{
		if (qsquotes(str, &open, i, &bl) == 3 && ++len)
			continue ;
		if ((str[i] != '\"' && str[i] != '\'')
			|| (open == 1 && str[i] == '\"')
			|| (open == 2 && str[i] == '\'')
			|| (bl))
			len++;
		bl = 0;
	}
	return (len);
}

void	ft_strrem_q(char **str)
{
	int		open;
	int		bl;
	int		i;
	int		y;
	char	*new;

	if (!str || !*str)
		return ;
	new = (char *)ft_calloc(strqlen(*str) + 1, sizeof(char));
	open = 0;
	bl = 0;
	i = -1;
	y = -1;
	while (str[0][++i])
	{
		if (qsquotes(*str, &open, i, &bl) == 3)
			continue ;
		if ((str[0][i] != '\"' && str[0][i] != '\'')
			|| (open == 1 && str[0][i] == '\"')
			|| (open == 2 && str[0][i] == '\'')
			|| (bl))
			new[++y] = str[0][i];
		bl = 0;
	}
	ft_nfreestr(str);
	*str = new;
}
