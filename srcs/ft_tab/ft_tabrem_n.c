/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_tabrem_n.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/24 21:36:20 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/25 23:34:50 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabrem_n(char **old, int n)
{
	int		i;
	char	**new;

	if (!old || n < 0)
		return (NULL);
	if (!old[0])
		return (old);
	new = (char **)ft_calloc(ft_tablen(old), sizeof(char *));
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
