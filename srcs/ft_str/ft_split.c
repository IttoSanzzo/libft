/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 20:40:28 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/18 16:08:59 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int	count;
	int	flag;
	int	str_count;

	count = 0;
	flag = 1;
	str_count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
	{
		if (str[count] == c)
			flag = 1;
		else if (str[count] && flag == 1 && ++str_count)
			flag = 0;
		count++;
	}
	return (str_count);
}

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

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		count;
	int		array_count;
	int		start;

	if (!s)
		return (NULL);
	count = 0;
	array_count = 0;
	array = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array)
		return (NULL);
	while (array_count < count_words(s, c))
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
}
