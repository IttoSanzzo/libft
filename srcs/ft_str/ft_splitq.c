/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_splitq.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 20:40:28 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/23 21:15:02 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	wc(char const *s, char c)
{
	int	wcount;
	int	open;
	int	flag;
	int	i;

	open = -1;
	i = -1;
	flag = 1;
	wcount = 0;
	while (s[++i])
	{
		if (s[i] == c && !(i > 0 && s[i - 1] == '\\'))
			open = -open;
		if (s[i] == ' ' && open == -1)
			flag = 1;
		else if (s[i] && flag == 1 && ++wcount)
			flag = 0;
	}
	return (wcount);
}

static int	wlen(char const *s, char c)
{
	int	wlen;
	int	open;
	int	i;

	open = -1;
	i = -1;
	wlen = 0;
	while (s[++i])
	{
		if (s[i] == '\\' || s[i] == c)
		{
			if (s[i] == '\\' && s[++i])
				wlen++;
			if (s[i] == c)
				open = -open;
			if (s[i])
				continue ;
		}
		if ((s[i] == ' ' && open == -1) || s[i] == '\0')
			break ;
		wlen++;
	}
	return (wlen);
}

/*
static char	*ft_newstring(char const *str, int count, int start, char c)
{
	char		*temp_string;
	int			count2;

	count2 = 0;
	temp_string = (char *)ft_calloc((count - start + 1), sizeof(char));
	if (!temp_string)
		return (NULL);
	while (str[start] != c && str[start])
		temp_string[count2++] = str[start++];
	temp_string[count2] = '\0';
	return (temp_string);
}
*/
char	**ft_splitq(char const *s, char c)
{
/*	char	**array;
	int		count;
	int		array_count;
	int		start;

	if (!s)
		return (NULL);
	count = 0;
	array_count = 0;
	array = (char **)malloc(sizeof(char *) * (wc(s, c) + 1));
	if (!array)
		return (NULL);
	while (array_count < wc(s, c))
	{
		if (s[count] != c && s[count])
		{
			start = count;
			while (s[count] != c && s[count])
				count++;
			array[array_count++] = ft_newstring(s, count, start, c);
		}
		count++;
	}
	array[array_count] = NULL;
	return (array);
	*/
	ft_printc(C_NCYAN, "Palavras..: %d\n", wc(s, c));
	ft_printc(C_NCYAN, "wlen..: %d\n", wlen(s, c));
	return (NULL);
}
