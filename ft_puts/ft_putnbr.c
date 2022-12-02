/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:47:14 by akaniber          #+#    #+#             */
/*   Updated: 2022/11/30 10:23:47 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puts.h"
#include "../ft_printf.h"

int	ft_putnbr(long nbr, t_base base)
{
	static size_t	result;

	result = 0;
	if (nbr < 0 && base.is_substract)
	{
		result++;
		base.is_substract = 0;
		ft_putnbr(4294967296 + nbr, base);
	}
	else if (nbr < 0 && !base.is_substract)
	{
		result++;
		ft_putchar('-');
		ft_putnbr(-nbr, base);
	}
	else if (nbr < base.base_length)
		ft_putchar(base.base[nbr]);
	else
	{
		ft_putnbr(nbr / base.base_length, base);
		ft_putchar(base.base[nbr % base.base_length]);
	}
	result++;
	return (result);
}
