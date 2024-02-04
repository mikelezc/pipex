/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:02:32 by mlezcano          #+#    #+#             */
/*   Updated: 2023/10/12 08:40:10 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	if ((size_t)dst - (size_t)src < len)
	{
		i = len - 1;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/*
Sirve para copiar un bloque de memoria desde un origen (src) 
a un destino (dst) de un tamaño len de bytes. 
La diferencia principal respecto a ft_memcpy es 
que es segura en caso de solapamiento 
entre las regiones de memoria origen y destino.

if ((size_t)dst - (size_t)src < len) 
Aquí está la comprobación para saber si hay solapamiento 
entre src y dst. 
Se restan punteros casteados a size_t 
y comparando si la diferencia es menor que len. 
Si hay solapamiento, se ejecutará if, 
si no, se ejecutará else.

i = len - 1;: Si hay solapamiento:
Copia los datos desde el final de la región de origen 
hacia el final de la región de destino,
de lo contrario, comienza desde el principio 
y avanza hacia el final.
*/
