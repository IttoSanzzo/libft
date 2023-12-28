/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_gint.c                                          :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/27 21:17:31 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/27 22:00:00 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

double	ft_gint(double val, size_t id)
{
	static int	save[GMEM_BUFFER];

	if (id > GMEM_BUFFER - 1)
		return (GETIV);
	if (val == GETIV)
		return (save[id]);
	if (val < INT_MIN || val > INT_MAX)
		return (GETIV);
	save[id] = (int)val;
	return (save[id]);
}
