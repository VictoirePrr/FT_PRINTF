/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:45:40 by vicperri          #+#    #+#             */
/*   Updated: 2024/11/19 16:17:01 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsign_nbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_unsign_nbr((n / 10));
		count += ft_unsign_nbr((n % 10));
	}
	else
		count += ft_putchar(n + 48);
	return (count);
}
