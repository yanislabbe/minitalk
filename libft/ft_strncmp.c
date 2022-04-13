/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:24:14 by ylabbe            #+#    #+#             */
/*   Updated: 2021/10/12 12:27:53 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*s;
	const unsigned char	*ss;
	size_t				i;

	s = (const unsigned char *)s1;
	ss = (const unsigned char *)s2;
	i = 0;
	while (s[i] != '\0' && ss[i] != '\0' && i < n)
	{
		if (s[i] != ss[i])
			return (s[i] - ss[i]);
		i++;
	}
	if (i < n && ((ss[i] != '\0' && s[i] == '\0') || (s[i] != '\0'
				&& ss[i] == '\0')))
		return (s[i] - ss[i]);
	return (0);
}
