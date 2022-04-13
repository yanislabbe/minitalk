/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:39:21 by ylabbe            #+#    #+#             */
/*   Updated: 2021/09/29 14:41:38 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_ft_putchar_fd(char c, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		get_ft_putchar_fd(45, fd);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		nbr = (nbr % 10 + '\0');
	}
	if (nbr <= 9)
	{
		get_ft_putchar_fd(nbr + 48, fd);
	}
}

static void	get_ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
