/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/29 10:02:53 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/30 00:16:37 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static char	*rl_wrap_up(t_readline *rl)
{
	rl_checkmove(rl);
	ft_putchar('\n');
	if (!ft_rlconfig(3, GETV, 0))
		return (rl->str);
	ft_rlconfig(3, PUTV, 0);
	ft_rlconfig(4, PUTV, 1);
	while (!ft_cquotes(rl->str))
	{
		rl->str = ft_stradd_end(rl->str, '\n');
		rl->str = ft_freejoin(rl->str, ft_readline("> "));
		if (!rl->str)
			break ;
	}
	ft_rlconfig(4, PUTV, 0);
	ft_rlconfig(3, PUTV, 1);
	if (ft_rlconfig(2, GETV, 0))
		return (ft_readline(rl->prompt));
	return (rl->str);
}

char	*rl_init(t_readline *rl, char *prompt)
{
	rl->str = ft_free(rl->str);
	rl->str = (char *)ft_calloc(1, sizeof(char));
	if (!rl->str)
		return (NULL);
	rl->move = 0;
	rl->his = ft_rlhistory(NULL);
	rl->hlen = ft_rlconfig(0, GETV, 0);
	rl->hpos = rl->hlen;
	rl->pos = 0;
	rl->len = 0;
	rl->ch = 0;
	rl->prompt = prompt;
	if (rl->prompt && !ft_rlconfig(2, GETV, 0))
		ft_putstr(rl->prompt);
	ft_rlconfig(2, PUTV, 0);
	ft_putstr("\033[s");
	return (rl->str);
}

static void	rl_others(t_readline *rl)
{
	if (rl->ch == '\033')
		rl_get_specials(rl);
	else if (rl_checkmove(rl) && rl->ch == '\t')
		rl_do_tab(rl);
	else if (rl->ch == 127 || rl->ch == 8)
		rl_do_backspace(rl);
	else if (rl->ch == '\f')
		rl_cleard(rl);
	else if (rl->ch == 11)
		rl->ch = rl->ch;
	else if (rl->ch != '\n' && rl->ch != 4)
		rl_addchar(rl);
}

char	*ft_readline(char *prompt)
{
	t_readline	rl;

	rl.str = NULL;
	if (!rl_init(&rl, prompt))
		return (NULL);
	while (rl.ch != '\n')
	{
		if (!rl_checkreset(&rl))
			rl.ch = ft_getchar();
		if (rl_checkreset(&rl) == 2)
			return (NULL);
		else if (rl_checkreset(&rl) == 1)
			continue ;
		if (rl.len == 0 && rl.ch == 4)
			return (ft_free(rl.str));
		else
			rl_others(&rl);
	}
	return (rl_wrap_up(&rl));
}
