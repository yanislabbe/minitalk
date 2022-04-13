/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:05:49 by ylabbe            #+#    #+#             */
/*   Updated: 2022/04/04 22:56:13 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef struct s_data
{
	int		count;
	int		value;
	va_list	ap;
}	t_data;

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		fta_strlen(char *format);
int		ft_putstr(char *format);
int		ft_putnbr(int nb);
int		ft_type_u(unsigned int n);
int		ft_type_x(unsigned long long nbr, char format);
int		ft_type_p(void *nbr, char format);
void	ft_cursor(char *format, t_data *data);

#endif
