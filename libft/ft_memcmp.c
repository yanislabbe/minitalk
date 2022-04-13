/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:54:37 by ylabbe            #+#    #+#             */
/*   Updated: 2022/04/04 22:58:04 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (n--)
	{
		if (((const unsigned char *)s1)[count] !=
				((const unsigned char *)s2)[count])
			return (((const unsigned char *)s1)[count] -
					((const unsigned char *)s2)[count]);
		count++;
	}
	return (0);
}
