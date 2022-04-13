/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:43:24 by ylabbe            #+#    #+#             */
/*   Updated: 2021/10/11 14:42:30 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*dst2;
	const char	*src2;
	size_t		len;
	size_t		dstlen;

	dst2 = dst;
	src2 = src;
	len = dstsize;
	while (len-- != 0 && (*dst2) != '\0')
		dst2++;
	dstlen = dst2 - dst;
	len = dstsize - dstlen;
	if (len == 0)
		return (dstlen + ft_strlen(src2));
	while ((*src2) != '\0')
	{
		if (len != 1)
		{
			(*dst2++) = (*src2);
			len--;
		}
		src2++;
	}
	(*dst2) = '\0';
	return (dstlen + (src2 - src));
}
