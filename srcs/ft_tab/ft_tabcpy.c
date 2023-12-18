/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/12 20:40:40 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/12 20:51:15 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabcpy(char **old)
{
	int		i;
	char	**tab;

	if (!old)
		return (NULL);
	tab = (char **)ft_calloc(ft_tablen(old) + 1, sizeof(char *));
	i = -1;
	while (old[++i])
		tab[i] = ft_strdup(old[i]);
	return (tab);
}
