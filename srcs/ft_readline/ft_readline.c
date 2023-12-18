/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/08 09:13:14 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/08 09:33:51 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_rl_jf(char *line, char *buffer)
{
	char	*new;

	new = ft_strjoin(line, buffer);
	free(line);
	return (new);
}

char	*ft_readline(char *prompt)
{
	char	*line;
	char	buffer[1];

	ft_putstr(prompt);
	line = (char *)ft_calloc(2, sizeof(char));
	if (!line)
		return (NULL);
	read(0, buffer, 1);
	while (*buffer != '\n')
	{
		line = ft_rl_jf(line, buffer);
		if (read(0, buffer, 1) == -1)
			break ;
	}
	return (line);
}
