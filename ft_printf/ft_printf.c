/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:11:30 by ylabbe            #+#    #+#             */
/*   Updated: 2022/04/04 22:57:09 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	init_data(void)
{
	t_data	data;

	data.count = 0;
	data.value = 0;
	return (data);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *format)
{
	if (format == NULL)
		return (write(1, "(null)", 6));
	return (write(1, format, fta_strlen(format)));
}

void	ft_cursor(char *format, t_data *data)
{
	if (format[data->count] != '%')
		data->value += ft_putchar(format[data->count]);
	if (format[data->count] == '%')
	{
		data->count++;
		if (format[data->count] == 'd' || format[data->count] == 'i')
			data->value += ft_putnbr(va_arg(data->ap, int));
		else if (format[data->count] == 'c')
			data->value += ft_putchar((char)va_arg(data->ap, int));
		else if (format[data->count] == 's')
			data->value += ft_putstr(va_arg(data->ap, char *));
		else if (format[data->count] == 'p')
			data->value += ft_type_p(va_arg(data->ap, void *),
					format[data->count]);
		else if (format[data->count] == 'x' || format[data->count] == 'X')
			data->value += ft_type_x(va_arg(data->ap, unsigned int),
					format[data->count]);
		else if (format[data->count] == 'u')
			data->value += ft_type_u(va_arg(data->ap, unsigned int));
		else if (format[data->count] == '%')
			data->value += ft_putchar('%');
	}
}

int	ft_printf(const char *format, ...)
{
	t_data	data;

	data = init_data();
	va_start(data.ap, (char *)format);
	while (format[data.count])
	{
		ft_cursor((char *)format, &data);
		data.count++;
	}
	return (data.value);
}
