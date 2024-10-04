/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:14:36 by emalungo          #+#    #+#             */
/*   Updated: 2024/10/04 12:37:58 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Prs an unsigned integer and returns the count of digits.

int	ft_putnbr_unsigned(unsigned int number)
{
	char	*str;
	int		count;

	count = 0;
	str = "0123456789";
	if (number > 9)
		count += ft_putnbr_unsigned(number / 10);
	count += ft_putchar(str[number % 10]);
	return (count);
}
