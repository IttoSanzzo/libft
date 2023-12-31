/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_clstnval.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/31 00:54:17 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/31 01:31:03 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	ft_clstnval(t_clist *lst, int pos)
{
	t_clist	*temp;

	if (!lst || pos < 0)
		return ('\0');
	temp = ft_clstpos(lst, pos);
	if (!temp)
		return ('\0');
	return (temp->val);
}
