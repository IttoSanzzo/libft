/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstrem_bgn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itto <Itto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:36:09 by Itto              #+#    #+#             */
/*   Updated: 2024/01/19 19:36:11 by Itto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstrem_bgn(t_clist **lst)
{
	t_clist	*temp;

	if (!*lst)
		return (NULL);
	temp = *lst;
	*lst = temp->next;
	free(temp);
	return (*lst);
}
