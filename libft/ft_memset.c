/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:46:38 by ylabbe            #+#    #+#             */
/*   Updated: 2021/10/08 20:00:44 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			count;
	unsigned char	*str;

	str = (unsigned char *)b;
	count = 0;
	if (!&ft_memset)
		return (NULL);
	while (count < len)
		str[count++] = c;
	return (b);
}
