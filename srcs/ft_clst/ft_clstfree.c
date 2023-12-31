/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_clstfree.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 19:34:24 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/30 21:23:00 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	ft_clstfree(t_clist **lst)
{
	t_clist	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	lst = NULL;
}
