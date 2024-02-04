/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:54:13 by mlezcano          #+#    #+#             */
/*   Updated: 2023/11/25 11:01:53 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	negative;
	int	count;
	int	number;

	count = 0;
	negative = 1;
	number = 0;
	while ((str[count] >= '\t' && str[count] <= '\r') || str[count] == ' ')
		count++;
	if (str[count] == '-')
		negative = -1;
	if (str[count] == '+' || str[count] == '-')
		count++;
	while (str[count] >= '0' && str[count] <= '9')
	{
		number = (str[count] - '0') + (number * 10);
		count++;
	}
	return (number * negative);
}
