/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:45:40 by vicperri          #+#    #+#             */
/*   Updated: 2024/11/18 17:11:30 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_nbr(unsigned long n, char x)
{
	char *base_maj;
	char *base_min;
	int count;

	count = 0;
	base_maj = "0123456789ABCDEF";
	base_min = "0123456789abcdef";
	if (n >= 16)
		count += ft_hexa_nbr((n / 16), x);
	if (x == 'X')
		count += ft_putchar(base_maj[n % 16]);
	if (x == 'x')
		count += ft_putchar(base_min[n % 16]);
	return (count);
}