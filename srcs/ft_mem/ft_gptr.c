/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_gptr.c                                          :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/27 21:17:31 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/27 22:02:51 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	*ft_gptr(void *ptr, size_t id)
{
	static void	*save[GMEM_BUFFER];

	if (id > GMEM_BUFFER - 1)
		return (NULL);
	if (ptr == GETPV)
		return (save[id]);
	save[id] = ptr;
	return (save[id]);
}
