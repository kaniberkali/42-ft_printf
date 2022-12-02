/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:28:06 by akaniber          #+#    #+#             */
/*   Updated: 2022/11/30 10:21:17 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puts.h"

int	ft_putstr(char *str)
{
	size_t	result;

	result = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[result])
	{
		ft_putchar(str[result]);
		result++;
	}
	return (result);
}
