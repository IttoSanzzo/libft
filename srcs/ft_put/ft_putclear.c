/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_putclear.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/27 20:55:14 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/27 20:59:39 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	ft_putclear(void)
{
	ft_putstr("\e[1;1H\e[2J");
}
