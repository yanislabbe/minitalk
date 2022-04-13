/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:21:34 by ylabbe            #+#    #+#             */
/*   Updated: 2021/10/12 12:27:14 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*retour;

	if ((unsigned char)c == '\0')
		return (ft_strchr(s, '\0'));
	retour = NULL;
	while (ft_strchr(s, c) != NULL)
	{
		retour = ft_strchr(s, c);
		s = ft_strchr(s, c) + 1;
	}
	return ((char *)retour);
}
