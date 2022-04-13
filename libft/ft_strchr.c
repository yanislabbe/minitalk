/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:13:53 by ylabbe            #+#    #+#             */
/*   Updated: 2021/09/29 15:36:30 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (c == '\0')
	{
		while (--len >= 0)
			++s;
		return ((char *)s);
	}
	while ((*s))
	{
		if ((*s) == (unsigned char)c)
			return ((char *)s);
		++s;
	}
	return (NULL);
}
