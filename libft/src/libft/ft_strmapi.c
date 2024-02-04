/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:56:21 by mlezcano          #+#    #+#             */
/*   Updated: 2023/09/25 14:46:59 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	res = malloc(ft_strlen(s) +1 * sizeof(char));
	i = 0;
	if (!s || !f)
		return (NULL);
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
A cada carácter de la string ’s’, aplica la
función ’f’ dando como parámetros el índice de cada carácter 
dentro de ’s’ y el propio carácter. Genera una 
nueva string con el resultado del uso sucesivo de ’f’

-Retorna:
La string creada tras el correcto uso de ’f’ sobre cada carácter.
NULL si falla la reserva de memoria.

-Parámetros:
s: La string que iterar.
f: La función a aplicar sobre cada carácter.
*/
