/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_tabrem_bgn.c                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/24 21:36:20 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/25 23:34:40 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabrem_bgn(char **old)
{
	int		i;
	char	**new;

	if (!old)
		return (NULL);
	if (!old[0])
		return (old);
	new = (char **)ft_calloc(ft_tablen(old), sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	free(old[0]);
	while (old[++i])
		new[i - 1] = (char *)(old[i]);
	free(old);
	return (new);
}
