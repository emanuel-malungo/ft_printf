/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:07:23 by emalungo          #+#    #+#             */
/*   Updated: 2024/10/03 16:37:46 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_printf
{
	va_list	args;
}				t_printf;

int	ft_putchar(char c);
int	ft_putnbr(int number);
int	ft_putstr(const char *str);
int ft_putnbr_unsigned(unsigned int number);

#endif