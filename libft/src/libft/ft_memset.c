/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:38:48 by mlezcano          #+#    #+#             */
/*   Updated: 2023/10/12 08:40:16 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}
/*
Esta función escribe tantos bytes como definamos en len,
con el valor c, convertido en un unsigned chart al string b.  
unsigned char) to the string b.
Se retornará b con los valores asignados por c.
---
Unsigned char representa un byte (8 bits) de datos sin signo, 
Solo puede almacenar valores positivos o cero.
Se usa char con las funciones mem, en vez de un int,
porque precisamente ocupa un byte entero (8 bits).
En vez de 1 bit que es lo que ocupa un int. 
*/