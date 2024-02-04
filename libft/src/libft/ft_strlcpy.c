/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:18:29 by mlezcano          #+#    #+#             */
/*   Updated: 2023/10/12 08:40:58 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t sizedst)
{
	size_t	sizesrc;
	size_t	i;

	sizesrc = ft_strlen(src);
	i = 0;
	if (sizedst != 0)
	{
		while (i < (sizedst - 1) && src[i] != 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (sizesrc);
}
/*
Esta función sirve para copiar una cadena origen src
a una cadena destino dst, limitando la cantidad de caracteres 
con el valor entregado a través de sizedst.
Para ello comprobaremos primero si los punteros son nulos,
en caso de ser así retornaremos 0.
Luego llamamos a la función ft_strlen para calcular la 
cantidad de caracteresde la cadena src.
A continuación usamos el bucle para copiar una cadena a otra.
El -1 es para dejar libre un espacio para colocar en caracter nulo
el cual aportamos al salir del bucle con dst[i] = 0;
*/
