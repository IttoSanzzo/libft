/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_tabrem_end.c                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/24 21:36:20 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/25 23:34:34 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabrem_end(char **old)
{
	int		i;
	int		end;
	char	**new;

	if (!old)
		return (NULL);
	if (!old[0])
		return (old);
	end = ft_tablen(old);
	new = (char **)ft_calloc(end, sizeof(char *));
	if (!new)
		return (NULL);
	i = -1;
	while (++i < end - 1)
		new[i] = (char *)(old[i]);
	free(old[i]);
	free(old);
	return (new);
}
