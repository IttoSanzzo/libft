/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   rl_utils.c                                         :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/29 10:35:22 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/31 15:50:03 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	rl_addchar(t_readline *rl)
{
	int	save[2];

	ft_clstadd_n(&rl->line, ft_clstnew(rl->ch), rl->pos);
	rl->len++;
	ft_ansi_getcp(&save[0], &save[1]);
	ft_putclstpos(rl->line, rl->pos);
	rl_save_end(rl);
	ft_ansi_go(save[0], save[1]);
	rl_go_right(rl);
}

void	rl_get_back(t_readline *rl)
{
	int	save;

	if (rl->pos == rl->len)
		return ;
	save = rl->pos;
	if (rl->pos >= rl->len % 2)
	{
		rl->pos = rl->len;
		while (rl->pos != save)
			rl_go_left(rl);
	}
	else
	{
		rl_go_home(rl);
		while (rl->pos != save)
			rl_go_right(rl);
	}
}

void	rl_cleard(t_readline *rl)
{
	ft_ansi_dfd();
	if (rl->prompt)
		ft_putstr(rl->prompt);
	rl_save_home(rl);
	ft_putclst(rl->line);
	rl_save_end(rl);
	rl_get_back(rl);
}

char	rl_bufferuse(t_readline *rl)
{
	rl->ch = rl->buffer->val;
	ft_clstrem_bgn(&rl->buffer);
	return (rl->ch);
}
