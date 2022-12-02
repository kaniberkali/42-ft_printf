/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:56:21 by akaniber          #+#    #+#             */
/*   Updated: 2022/11/30 17:46:38 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_puts/ft_puts.h"

t_base	ft_create_base(char format)
{
	t_base	base;

	base.is_substract = 0;
	if (format == 'd' || format == 'i' || format == 'u')
	{
		if (format == 'u')
			base.is_substract = 1;
		base.base = "0123456789";
		base.base_length = 10;
	}
	else
	{
		if (format == 'X')
		base.base = "0123456789ABCDEF";
		else
		base.base = "0123456789abcdef";
		base.base_length = 16;
	}
	return (base);
}

int	ft_print_varriable(va_list args, char c, t_base base)
{
	int					result;
	unsigned long long	nbr;

	result = 0;
	if (c == 's')
		result += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
	{
		result += ft_putstr("0x");
		nbr = va_arg(args, unsigned long long);
		if (nbr > 922337203685477580)
		{
			result += ft_putnbr((long)(nbr / base.base_length), base);
			result += ft_putchar(base.base[nbr % base.base_length]);
		}
		else
			result += ft_putnbr(nbr, base);
	}
	else if (c == 'x' || c == 'X' || c == 'u')
		result += ft_putnbr(va_arg(args, unsigned int), base);
	else if (c == 'd' || c == 'i')
		result += ft_putnbr(va_arg(args, int), base);
	else
		result += (ft_putchar(va_arg(args, int)));
	return (result);
}

int	ft_printf(const char *format, ...)
{
	t_base	base;
	int		result;
	int		id;
	va_list	args;

	va_start(args, format);
	result = 0;
	id = 0;
	while (format[id])
	{
		if (format[id] == '%' && format[++id] != '%')
		{
			base = ft_create_base(format[id]);
			result += ft_print_varriable(args, format[id], base);
		}
		else
			result += ft_putchar(format[id]);
		id++;
	}
	va_end(args);
	return (result);
}
