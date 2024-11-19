/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_void.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:45:40 by vicperri          #+#    #+#             */
/*   Updated: 2024/11/19 16:16:24 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_recursive(unsigned long int p, char *base_min)
{
	int	count;

	count = 0;
	if (p >= 16)
		count += ft_hexa_recursive(p / 16, base_min);
	count += ft_putchar(base_min[p % 16]);
	return (count);
}

int	ft_hexa_void(unsigned long int p)
{
	char	*base_min;
	int		count;

	base_min = "0123456789abcdef";
	count = 0;
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += write(1, "0x", 2);
	count += ft_hexa_recursive(p, base_min);
	return (count);
}
