/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itto <Itto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:29:23 by Itto              #+#    #+#             */
/*   Updated: 2024/01/19 19:29:24 by Itto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

// Struct Define
typedef struct s_list
{
	void			*val;
	struct s_list	*next;
}	t_list;

typedef struct s_clist
{
	char			val;
	struct s_clist	*next;
}	t_clist;

typedef struct s_readline
{
	int				home[2];
	int				end[2];
	int				move;
	int				hlen;
	int				hpos;
	int				spos;
	int				vpos;
	int				pos;
	int				len;
	char			**his;
	char			ch;
	const char		*prompt;
	struct s_clist	*line;
	struct s_clist	*buffer;
}	t_readline;

#endif
