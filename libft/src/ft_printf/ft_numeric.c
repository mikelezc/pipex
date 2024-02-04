/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numeric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:13:17 by mlezcano          #+#    #+#             */
/*   Updated: 2023/10/12 10:57:03 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrl(int nbr, int *length)
{
	if (nbr == -2147483648)
	{
		write (1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (nbr < 0)
	{
		ft_putcharl('-', length);
		ft_putnbrl(nbr * -1, length);
	}
	else
	{
		if (nbr > 9)
			ft_putnbrl(nbr / 10, length);
		ft_putcharl(nbr % 10 + '0', length);
	}
}

void	ft_puthexal(unsigned long long nbr, char *base, int	*length)
{
	if (nbr >= 16)
	{
		ft_puthexal(nbr / 16, base, length);
		ft_puthexal(nbr % 16, base, length);
	}
	else
		ft_putcharl(base[nbr], length);
}

void	ft_putunsl(unsigned int num, int *len)
{
	if (num >= 10)
	{
		ft_putunsl(num / 10, len);
		ft_putunsl(num % 10, len);
	}
	else
		ft_putcharl(num + '0', len);
}
