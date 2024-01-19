/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itto <Itto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:36:28 by Itto              #+#    #+#             */
/*   Updated: 2024/01/19 19:36:30 by Itto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstnew(char val)
{
	t_clist	*newlst;

	newlst = (t_clist *)malloc(sizeof(t_clist));
	if (!newlst)
		return (NULL);
	newlst->val = val;
	newlst->next = NULL;
	return (newlst);
}
