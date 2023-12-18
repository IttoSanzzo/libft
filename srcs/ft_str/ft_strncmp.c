/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 20:45:56 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/10/27 20:46:03 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		return (0);
	while (s1[count] && (s1[count] == s2[count]) && count < (n - 1))
		count++;
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
