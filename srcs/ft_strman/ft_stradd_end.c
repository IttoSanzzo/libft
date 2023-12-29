/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_stradd_end.c                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/24 21:36:20 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/28 23:54:20 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd_end(char *old, char add)
{
	int		i;
	char	*new;

	if (!old)
		return (NULL);
	new = (char *)ft_calloc(ft_strlen(old) + 2, sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (old[++i])
		new[i] = (char)(old[i]);
	new[i] = (char)(add);
	free(old);
	return (new);
}
