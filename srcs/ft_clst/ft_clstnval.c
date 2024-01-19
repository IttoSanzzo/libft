/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstnval.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itto <Itto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:36:22 by Itto              #+#    #+#             */
/*   Updated: 2024/01/19 19:36:24 by Itto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//returns the char stored in the "pos" position os a clist.
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
