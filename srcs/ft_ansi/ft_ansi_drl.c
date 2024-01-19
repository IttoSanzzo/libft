/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ansi_drl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itto <Itto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:31:06 by Itto              #+#    #+#             */
/*   Updated: 2024/01/19 19:31:07 by Itto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ansi_drl(char *prompt)
{
	if (prompt)
		ft_putstr(prompt);
	ft_putstr("\033[0K");
}
