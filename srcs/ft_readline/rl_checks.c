/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   rl_checks.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/29 10:14:37 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 11:30:34 by marcosv2         ###   ########.fr       */
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
	char		temp;

	if (safety > 0)
	{
		safety--;
		return (safety);
	}
	if (ft_rlconfig(2, GETV, 0))
	{
		rl_checkmove(rl);
		temp = rl->ch;
		rl_init(rl, rl->prompt, 0);
		rl->ch = temp;
		safety = 2;
		return (1);
	}
	return (0);
}
