/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:36:14 by mlezcano          #+#    #+#             */
/*   Updated: 2023/10/12 12:10:12 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_typearg(va_list argmnts, const char type, int *length)
{
	if (type == 'c')
		ft_putcharl(va_arg(argmnts, int), length);
	else if (type == 's')
		ft_putstrl(va_arg(argmnts, char *), length);
	else if (type == 'd' || type == 'i')
		ft_putnbrl(va_arg(argmnts, int), length);
	else if (type == 'u')
		ft_putunsl(va_arg(argmnts, unsigned int), length);
	else if (type == 'x')
		ft_puthexal(va_arg(argmnts, unsigned int), "0123456789abcdef", length);
	else if (type == 'X')
		ft_puthexal(va_arg(argmnts, unsigned int), "0123456789ABCDEFG", length);
	else if (type == '%')
		ft_putcharl('%', length);
	else if (type == 'p')
	{
		ft_putstrl("0x", length);
		ft_puthexal(va_arg(argmnts, unsigned long long),
			"0123456789abcdef", length);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	argmnts;

	i = 0;
	length = 0;
	va_start(argmnts, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_typearg(argmnts, str[i + 1], &length);
			i++;
		}
		else
			ft_putcharl(str[i], &length);
		i++;
	}
	va_end(argmnts);
	return (length);
}
