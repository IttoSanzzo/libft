/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_sujoin.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/12 16:32:12 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/25 21:39:56 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sujoin(char *s1, char *s2)
{
	char	*sujoin;

	sujoin = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (sujoin);
}
