/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:27:17 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/19 11:33:56 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_ext(char *file, char *ext)
{
	int	i;
	int	len;

	if (!file || !ext)
		return (0);
	len = ft_strlen(ext) + 1;
	i = ft_strlen(file);
	while (file[--i])
	{
		if (file[i] == '.' && !ft_strncmp((char *)(file + i + 1), file, len))
			return (1);
		else if (file[i] == '.')
			return (1);
	}
	return (0);
}
