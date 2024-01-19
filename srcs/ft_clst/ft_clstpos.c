/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itto <Itto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:36:17 by Itto              #+#    #+#             */
/*   Updated: 2024/01/19 19:36:18 by Itto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstpos(t_clist *lst, int pos)
{
	t_clist	*temp;

	if (!lst || pos < 0)
		return (NULL);
	temp = lst;
	while (pos-- && temp)
		temp = temp->next;
	if (pos + 1)
		return (NULL);
	return (temp);
}
