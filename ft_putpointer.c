/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:19:56 by emalungo          #+#    #+#             */
/*   Updated: 2024/10/04 12:36:59 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Prints a pointer's address in hexadecimal format.

int	ft_putpointer(void *ptr)
{
	uintptr_t	address;
	int			count;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	address = (uintptr_t)ptr;
	count += ft_putstr("0x");
	count += ft_putnbr_hex(address, 'x');
	return (count);
}
