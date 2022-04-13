/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:57:53 by ylabbe            #+#    #+#             */
/*   Updated: 2021/10/06 17:57:54 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*retour;
	size_t	lens1;
	size_t	lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	retour = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!retour)
		return (NULL);
	ft_strlcpy(retour, s1, lens1 + 1);
	ft_strlcat(retour + (lens1), s2, lens2 + 1);
	return (retour);
}
