/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:08:39 by emalungo          #+#    #+#             */
/*   Updated: 2024/10/04 12:54:49 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_format(t_printf *pf, char *format)
{
	if (*format == 'c')
		pf->count += ft_putchar(va_arg(pf->args, int));
	else if (*format == 's')
		pf->count += ft_putstr(va_arg(pf->args, char *));
	else if (*format == 'd' || *format == 'i')
		pf->count += ft_putnbr(va_arg(pf->args, int));
	else if (*format == 'u')
		pf->count += ft_putnbr_unsigned(va_arg(pf->args, unsigned int));
	else if (*format == 'x' || *format == 'X')
		pf->count += ft_putnbr_hex(va_arg(pf->args,
					unsigned long long), *format);
	else if (*format == 'p')
		pf->count += ft_putpointer(va_arg(pf->args, void *));
	else
		pf->count += ft_putchar(*format);
}

int	ft_printf(char *format, ...)
{
	t_printf	*pf;
	int			total_count;

	pf = (t_printf *)malloc(sizeof(t_printf));
	pf->count = 0;
	va_start(pf->args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				pf->count += ft_putchar('%');
			else
				ft_format(pf, format);
		}
		else
			pf->count += ft_putchar(*format);
		format++;
	}
	va_end(pf->args);
	total_count = pf->count;
	free(pf);
	return (total_count);
}
