/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstrem_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itto <Itto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:35:53 by Itto              #+#    #+#             */
/*   Updated: 2024/01/19 19:36:05 by Itto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstrem_end(t_clist **lst)
{
	t_clist	*last;

	if (!*lst)
		return (NULL);
	last = *lst;
	if (!last->next)
		return (ft_nfreeclst(lst));
	while (last->next->next)
		last = last->next;
	ft_nfreeclst(&last->next);
	return (*lst);
}
