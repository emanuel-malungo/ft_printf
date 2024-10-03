/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:46:41 by emalungo          #+#    #+#             */
/*   Updated: 2024/10/03 16:37:31 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Writes a character to standard output.
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
// Writes a string and returns its length.
int ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
// Prints an integer and returns the count of digits.
int	ft_putnbr(int number)
{
	char str[10] = "0123456789";
	int		count;

	count = 0;
	if (number == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
    	number = 147483648;
		count += 2;
	}
	else if (number < 0)
	{
		number *= -1;
		ft_putchar('-');
		count++;
	}
	if (number > 9)
		count += ft_putnbr(number / 10);
	ft_putchar(str[number % 10]);
	return (count + 1);
}
// Prints an unsigned integer and returns the count of digits.
int ft_putnbr_unsigned(unsigned int number)
{
	char str[10] = "0123456789";
	int count;
	
	count = 0;
	if (number > 9)
		count += ft_putnbr_unsigned(number / 10);
	ft_putchar(str[number % 10]);
	return (count + 1);
}
// Prints an unsigned long in lowercase hexadecimal.
int ft_putnbr_hex(unsigned long number)
{
	int	count;
	char *str[16] = "0123456789abcdef";

	count = 0;
	if (number > 15)
		count += ft_putnbr_hex(number / 16);
	ft_putchar(str[number % 16]);
	return (count + 1);
}
// Prints an unsigned long in uppercase hexadecimal.
int ft_putnbr_hex_upper(unsigned long number)
{
	int	count;
	char *str[16] = "0123456789ABCDEF";

	count = 0;
	if (number > 15)
		count += ft_putnbr_hex(number / 16);
	ft_putchar(str[number % 16]);
	return (count + 1);
}
// Prints a pointer's address in hexadecimal format.
void ft_putpointer(void *ptr)
{
	unsigned long addres;
	
	addres = (unsigned long)ptr;
	ft_putstr("0x");
	ft_putnbr_hex(addres);
}