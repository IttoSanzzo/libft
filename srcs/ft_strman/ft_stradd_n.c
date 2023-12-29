/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_stradd_n.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/24 21:36:20 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 00:42:03 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd_n(char *old, char add, int n)
{
	int		i;
	char	*new;

	if (!old || n < 0)
		return (NULL);
	new = (char *)ft_calloc(ft_strlen(old) + 2, sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (old[++i] && i < n)
		new[i] = (char)(old[i]);
	new[i] = (char)(add);
	while (old[++i - 1])
		new[i] = (char)(old[i - 1]);
	free(old);
	return (new);
}
