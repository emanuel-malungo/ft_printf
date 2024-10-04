/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:16:09 by emalungo          #+#    #+#             */
/*   Updated: 2024/10/04 12:48:30 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Prints an unsigned long in lowercase hexadecimal.

int	ft_putnbr_hex(unsigned long long number, char c)
{
	char	*str;
	int		count;

	count = 0;
	str = "0123456789abcdef";
	if (c != 'x' && c != 'X')
		return (0);
	if (number > 15)
		count += ft_putnbr_hex(number / 16, c);
	if (c == 'X')
		count += ft_putchar(str[number % 16] - 32);
	else
		count += ft_putchar(str[number % 16]);
	return (count);
}
