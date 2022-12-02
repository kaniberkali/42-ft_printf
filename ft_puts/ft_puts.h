/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:24:43 by akaniber          #+#    #+#             */
/*   Updated: 2022/11/30 10:21:08 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTS_H
# define FT_PUTS_H

# include <unistd.h>
# include "../ft_printf.h"

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(long nbr, t_base base);

#endif