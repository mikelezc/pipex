/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:53:07 by mlezcano          #+#    #+#             */
/*   Updated: 2023/10/12 08:39:51 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
/*
Sirve para encontrar la primera aparición de c 
(convertido a un unsigned char) en la cadena s.
- *s es el puntero a la cadena donde queremos localizar a c
- c es el caracter que queremos encontrar
- n es el número de bytes en donde le decimos
a la función que busque el carácter c. 

Debemos retornar un puntero al byte 
localizado (por eso retornamos un puntero void)
O retornamos NULL si no lo encontramos dentro de esos n bytes.
*/
