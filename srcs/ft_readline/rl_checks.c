/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   rl_checks.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/29 10:14:37 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 22:04:59 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

int	rl_checkmove(t_readline *rl)
{
	if (rl->move)
	{
		ft_free(rl->str);
		rl->str = ft_strdup(rl->his[rl->hpos]);
		rl->hpos = rl->hlen;
		rl->move = 0;
	}
	return (1);
}

int	rl_checkreset(t_readline *rl)
{
	static int	safety;

	if (ft_rlconfig(4, GETV, 0) != 2 && safety > 0)
	{
		safety--;
		return (safety);
	}
	else if (ft_rlconfig(2, GETV, 0))
	{
		rl_checkmove(rl);
		ft_ungetchar(rl->ch);
		if (ft_rlconfig(4, GETV, 0))
		{
			rl->str = (char *)ft_free(rl->str);
			return (2);
		}
		rl_init(rl, rl->prompt);
		safety = 2;
		return (1);
	}
	return (0);
}
