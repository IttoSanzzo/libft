/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itto <Itto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:36:41 by Itto              #+#    #+#             */
/*   Updated: 2024/01/19 19:36:42 by Itto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstadd_n(t_clist **lst, t_clist *new, int n)
{
	int		i;
	t_clist	*temp;

	if (!new || n < 0)
		return (NULL);
	if (!*lst || n == 0)
		return (ft_clstadd_bgn(lst, new));
	i = 0;
	temp = *lst;
	while (temp->next && ++i < n)
		temp = temp->next;
	if (temp->next)
		new->next = temp->next;
	temp->next = new;
	return (*lst);
}
