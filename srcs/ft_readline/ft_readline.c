/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/29 10:02:53 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 13:07:53 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static char	*rl_wrap_up(t_readline *rl)
{
	rl_checkmove(rl);
	ft_putchar('\n');
	return (rl->str);
}

char	*rl_init(t_readline *rl, char *prompt, int prt)
{
	rl->str = ft_free(rl->str);
	rl->str = (char *)ft_calloc(1, sizeof(char));
	if (!rl->str)
		return (NULL);
	ft_rlconfig(2, PUTV, 0);
	rl->move = 0;
	rl->his = ft_rlhistory(NULL);
	rl->hlen = ft_rlconfig(0, GETV, 0);
	rl->hpos = rl->hlen;
	rl->pos = 0;
	rl->len = 0;
	rl->ch = 0;
	rl->prompt = prompt;
	if (rl->prompt && prt)
		ft_putstr(rl->prompt);
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
	if (!rl_init(&rl, prompt, 1))
		return (NULL);
	while (rl.ch != '\n')
	{
		if (!rl_checkreset(&rl))
			rl.ch = ft_getchar();
		if (rl_checkreset(&rl))
			continue ;
		if (rl.len == 0 && rl.ch == 4)
			return (ft_free(rl.str));
		else
			rl_others(&rl);
	}
	return (rl_wrap_up(&rl));
}
