/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:32:34 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/19 16:48:17 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strchrem(char **str, char c)
{
	char	*ret;
	int		i;

	i = 0;
	while (str[0][i])
	{
		if (str[0][i] == c)
		{
			*(str[0] + i) = *(str[0] + i + 1);
			i++;
		}
		if (str[0][i])
			i++;
	}
	ret = ft_strdup(*str);
	ft_nfreestr(str);
	*str = ret;
}
