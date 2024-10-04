/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:11:15 by emalungo          #+#    #+#             */
/*   Updated: 2024/10/04 12:48:49 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Prints an integer and returns the count of digits.

int	ft_putnbr(int number)
{
	char	*str;
	int		count;

	count = 0;
	str = "0123456789";
	if (number == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	if (number < 0)
	{
		number = -number;
		count += ft_putchar('-');
	}
	if (number > 9)
		count += ft_putnbr(number / 10);
	count += ft_putchar(str[number % 10]);
	return (count);
}
