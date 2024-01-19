/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstrem_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itto <Itto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:35:42 by Itto              #+#    #+#             */
/*   Updated: 2024/01/19 19:35:48 by Itto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstrem_n(t_clist **lst, int n)
{
	int		i;
	t_clist	*temp;

	if (n < 0)
		return (NULL);
	if (!*lst || n == 0)
		return (ft_clstrem_bgn(lst));
	i = 0;
	temp = *lst;
	while (temp->next && ++i < n)
		temp = temp->next;
	ft_clstrem_bgn(&temp->next);
	return (*lst);
}
