/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:50:02 by ylabbe            #+#    #+#             */
/*   Updated: 2021/10/06 18:50:03 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	char	*retour;

	retour = 0;
	if (s1 != 0 && set != 0)
	{
		first = 0;
		last = ft_strlen(s1);
		while (s1[first] && ft_strchr(set, s1[first]))
			first++;
		while (s1[last - 1] && ft_strchr(set, s1[last - 1]) && last > first)
			last--;
		retour = (char *)malloc(sizeof(char) * (last - first + 1));
		if (retour)
			ft_strlcpy(retour, &s1[first], last - first + 1);
	}
	return (retour);
}
