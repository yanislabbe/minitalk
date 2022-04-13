/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:43:56 by ylabbe            #+#    #+#             */
/*   Updated: 2021/10/12 13:11:28 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_size(const char *str, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while ((*str))
	{
		if ((*str) != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if ((*str) == c)
			x = 0;
		str++;
	}
	return (count);
}

static void	next_str(char **str, int *strlen, char c)
{
	int	count;

	*str += *strlen;
	*strlen = 0;
	count = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[count])
	{
		if ((*str)[count] == c)
			break ;
		(*strlen)++;
		count++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split2;
	char	*str;
	int		strlen;
	int		strsize;
	int		count;

	if (!s)
		return (NULL);
	strsize = str_size(s, c);
	split2 = malloc(sizeof(char *) * (strsize + 1));
	if (!split2)
		return (NULL);
	count = 0;
	str = (char *)s;
	strlen = 0;
	while (count < strsize)
	{
		next_str(&str, &strlen, c);
		split2[count] = malloc(sizeof(char) * (strlen + 1));
		if (!split2)
			return (NULL);
		ft_strlcpy(split2[count++], str, strlen + 1);
	}
	split2[count] = NULL;
	return (split2);
}
