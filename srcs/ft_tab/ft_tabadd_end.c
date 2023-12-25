/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_tabadd_end.c                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/24 21:36:20 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/25 13:08:53 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabadd_end(char **old, char *add)
{
	int		i;
	char	**new;

	if (!old || !add)
		return (NULL);
	new = (char **)ft_calloc(ft_tablen(old) + 2, sizeof(char *));
	if (!new)
		return (NULL);
	i = -1;
	while (old[++i])
		new[i] = (char *)(old[i]);
	new[i] = (char *)(add);
	free(old);
	return (new);
}
