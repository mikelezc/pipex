/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:38:44 by mlezcano          #+#    #+#             */
/*   Updated: 2023/10/12 08:40:47 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t sizedst)
{
	size_t	a;
	size_t	b;

	if (sizedst <= ft_strlen(dst))
		return (sizedst + ft_strlen(src));
	a = ft_strlen(dst);
	b = 0;
	while (src[b] != 0 && a + 1 < sizedst)
	{
		dst[a] = src[b];
		a++;
		b++;
	}
	dst[a] = 0;
	return (ft_strlen(dst) + ft_strlen(&src[b]));
}

/*
Sirve para concatenar cadenas de manera segura, 
evitando desbordamientos de búfer.
Al final devuelve la longitud total de la cadena resultante.
---
Comprueba si el tamaño del destino es menor o igual que la longitud del destino.
Si es así, simplemente devuelve la suma del tamaño 
del destino y la longitud de la fuente.
    if (dstsize <= ft_strlen(dst))
*/
