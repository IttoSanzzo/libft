/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_rlhistory.c                                     :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/28 21:55:52 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 22:38:42 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	**ft_rlhistory(char *new)
{
	int			len;
	int			i;
	static char	**history;

	if (!new)
		return (history);
	if (!history)
	{
		history = (char **)ft_calloc(2, sizeof(char *));
		history[0] = ft_strdup(new);
	}
	else
	{
		len = ft_tablen(history);
		i = (ft_getrstr_p(history, new));
		if (i != -1 && i != len - 1)
			ft_tabsmove(history, i, len - 1);
		else
		{
			history = ft_tabadd_end(history, ft_strdup(new));
			ft_rlconfig(0, PUTV, len + 1);
		}
	}
	return (history);
}
