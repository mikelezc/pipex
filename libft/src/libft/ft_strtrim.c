/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:09:10 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/28 21:27:28 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	in;
	size_t	out;

	if (!s1 || !set)
		return (NULL);
	in = 0;
	out = ft_strlen(s1);
	while (s1[in] && ft_strchr(set, s1[in]))
		in++;
	while (ft_strchr(set, s1[out]) && out > in)
		out--;
	return (ft_substr(s1, in, (out - in +1)));
}

/*
Elimina todos los caracteres de la string ’set’ 
desde el principio y desde el final de ’s1’, 
hasta encontrar un caracter no perteneciente a ’set’. 
La string resultante se devuelve con una reserva de malloc(3)

s1: La string que debe ser recortada.
set: Los caracteres a eliminar de la string.

Devuelve:
La string recortada.
NULL si falla la reserva de memoria.
*/
