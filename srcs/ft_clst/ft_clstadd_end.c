/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itto <Itto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:35:29 by Itto              #+#    #+#             */
/*   Updated: 2024/01/19 19:35:30 by Itto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstadd_end(t_clist **lst, t_clist *new)
{
	t_clist	*last;

	if (!*lst)
	{
		*lst = new;
		return (*lst);
	}
	else if (new)
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return (*lst);
}
