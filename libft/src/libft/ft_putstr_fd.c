/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:59:17 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/28 21:23:37 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != 0)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

/*
Envía la string ’s’ al file descriptor especificado.
---
s: La string a enviar.
fd: El file descriptor sobre el que escribir.

N- exáctaamente igual que el anterior ft_putchar_fd
pero con un while para recorrer la cadena y que se imprima 
hasta carácter nulo
*/