/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   rl_go.c                                            :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/29 16:41:51 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/31 07:30:17 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static void	rl_force_end(void)
{
	int	bfr[2];
	int	aft[2];

	ft_ansi_getcp(&bfr[0], &bfr[1]);
	ft_printf("\033[%dC", RL_FORCE_END);
	ft_ansi_getcp(&aft[0], &aft[1]);
	if (bfr[0] != aft[0])
	{
		bfr[0] = aft[0];
		ft_printf("\033[%dC", RL_FORCE_END);
		ft_ansi_getcp(&aft[0], &aft[1]);
	}
}

void	rl_go_right(t_readline *rl)
{
	int	bfr[2];
	int	aft[2];

	if (rl->pos < rl->len)
	{
		ft_ansi_getcp(&bfr[0], &bfr[1]);
		ft_putstr("\033[C");
		ft_ansi_getcp(&aft[0], &aft[1]);
		if (bfr[0] == aft[0])
			ft_putstr("\033[1E");
		rl->pos++;
	}
}

void	rl_go_left(t_readline *rl)
{
	int	bfr[2];
	int	aft[2];

	if (rl->pos > 0)
	{
		ft_ansi_getcp(&bfr[0], &bfr[1]);
		ft_putstr("\033[D");
		ft_ansi_getcp(&aft[0], &aft[1]);
		if (bfr[0] == aft[0])
		{
			ft_putstr("\033[1F");
			rl_force_end();
		}
		rl->pos--;
	}
}
