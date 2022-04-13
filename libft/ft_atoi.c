/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:08:54 by ylabbe            #+#    #+#             */
/*   Updated: 2021/10/08 17:16:01 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\r' || c == '\f');
}

static int	retour_en_int(const char *str)
{
	int		count;
	int		sign;
	long	retour;

	count = 0;
	sign = 1;
	retour = 0;
	if (str[count] == '+' || str[count] == '-')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	while (str[count] != '\0' && ft_isdigit(str[count]))
	{
		if (count < 11)
			retour = retour * 10 + (str[count++] - '0');
		else if (sign == -1)
			return (0);
		else
			return (-1);
	}
	return (retour * sign);
}

int	ft_atoi(const char *str)
{
	while (is_space(str[0]))
		++str;
	return (retour_en_int(str));
}
