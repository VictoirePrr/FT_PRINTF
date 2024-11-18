/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:22:21 by vicperri          #+#    #+#             */
/*   Updated: 2024/11/18 17:16:29 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	parsing_format(char format)
{
	char	*string;
	int		i;

	string = "cspdiuxX";
	i = 0;
	if (format == '%')
		return (format);
	while (string[i])
	{
		if (string[i] == format)
			return (format);
		i++;
	}
	return (0);
}

int	conversion_format(const char *format, int i, va_list args)
{
	int	count;

	count = 0;
	if (format[i] == 'c')
		count = ft_putchar(va_arg(args, int));
	if (format[i] == 's')
		count = ft_putstr(va_arg(args, char *));
	if (format[i] == 'd' || format[i] == 'i')
		count = ft_putnbr(va_arg(args, int));
	if (format[i] == 'u')
		count = ft_unsign_nbr(va_arg(args, unsigned int));
	// if (format[i] == 'p')
	// 	count =
	if (format[i] == 'x')
		count = ft_hexa_nbr(va_arg(args, unsigned long int), format[i]);
	if (format[i] == 'X')
		count = ft_hexa_nbr(va_arg(args, unsigned long int), format[i]);
	if (format[i] == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	if (format == NULL)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (parsing_format(format[i]) != 0)
				len += conversion_format(format, i, args);
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
// int	main(void)
// {
// 	printf("%d", ft_printf(" %d ", -1));
// 	printf("%d", printf(" %d ", -1));
// 	return (0);
// }