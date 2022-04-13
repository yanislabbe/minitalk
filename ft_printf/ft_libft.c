/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:56:36 by ylabbe            #+#    #+#             */
/*   Updated: 2022/04/04 22:56:45 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fta_strlen(char *format)
{
	int	count;

	count = 0;
	while (format[count])
		count++;
	return (count);
}

int	ft_putnbr(int nb)
{
	static unsigned long	count;

	count = 0;
	if (nb < 0 && nb / 10 == 0)
		count += ft_putchar(45);
	if (nb / 10 != 0)
		ft_putnbr(nb / 10);
	if (nb % 10 < 0)
		count += ft_putchar(-(nb % 10) + '0');
	else
		count += ft_putchar((nb % 10) + '0');
	return (count);
}

int	ft_type_u(unsigned int n)
{
	static int	count;
	int			i;
	char		str[100];

	count = 0;
	i = 0;
	if (n == 0)
		count += ft_putchar('0');
	while (n > 0)
	{
		str[i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	i--;
	while (i >= 0)
		count += ft_putchar(str[i--]);
	return (count);
}

int	ft_type_x(unsigned long long nbr, char format)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_type_x(nbr / 16, format);
		count += ft_type_x(nbr % 16, format);
	}
	else
	{
		if (nbr <= 9)
			count += ft_putchar(nbr + '0');
		else
		{
			if (format == 'x')
				count += ft_putchar(nbr - 10 + 'a');
			else if (format == 'X')
				count += ft_putchar(nbr - 10 + 'A');
		}
	}
	return (count);
}

int	ft_type_p(void *nbr, char format)
{
	unsigned long	nb;
	int				count;

	nb = (unsigned long) nbr;
	format = 'x';
	count = 0;
	count += ft_putstr("0x");
	return (count += ft_type_x(nb, 'x'));
}
