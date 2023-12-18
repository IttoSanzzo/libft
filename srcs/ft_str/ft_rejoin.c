/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_rejoin.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/12 16:32:12 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/12 16:45:13 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rejoin(char	*s1, char *s2)
{
	char	*rejoin;

	rejoin = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (rejoin);
}
