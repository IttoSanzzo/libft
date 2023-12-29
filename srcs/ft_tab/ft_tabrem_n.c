/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_tabrem_n.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/24 21:36:20 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 01:10:01 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabrem_n(char **old, int n)
{
	int		end;
	int		i;
	char	**new;

	if (!old || n < 0)
		return (NULL);
	end = ft_tablen(old);
	if (!old[0] || n > end - 1)
		return (old);
	new = (char **)ft_calloc(end, sizeof(char *));
	if (!new)
		return (NULL);
	i = -1;
	while (old[++i] && i < n)
		new[i] = (char *)(old[i]);
	free(old[i]);
	while (old[++i])
		new[i - 1] = (char *)(old[i]);
	free(old);
	return (new);
}
