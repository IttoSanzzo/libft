/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_gmem.c                                          :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/27 21:17:31 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/27 21:24:06 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	*ft_gmem(void *ptr, int id)
{
	static void	*save[GMEM_BUFFER];

	if (ptr == NULL)
		return (save[id]);
	save[id] = ptr;
	return (save[id]);
}
