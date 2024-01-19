/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd_bgn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itto <Itto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:35:15 by Itto              #+#    #+#             */
/*   Updated: 2024/01/19 19:35:24 by Itto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstadd_bgn(t_clist **lst, t_clist *new)
{
	if (!*lst)
	{
		*lst = new;
		return (*lst);
	}
	if (new)
	{
		new->next = *lst;
		*lst = new;
		return (*lst);
	}
	return (NULL);
}
