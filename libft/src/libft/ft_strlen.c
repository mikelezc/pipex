/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:38:14 by mlezcano          #+#    #+#             */
/*   Updated: 2023/10/12 08:41:03 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}
/*
nos retorna un valor con la 
cantidad de caracteres que entregamos 
como argumento en la cadena s.

size_t se utiliza para hacer que el código sea más portable, 
ya que el tamaño de los tipos de datos puede variar en diferentes sistemas. 

Su tamaño en bytes depende de la arquitectura de la máquina, 
lo que significa que puede ser de 32 bits en sistemas de 32 bits 
o de 64 bits en sistemas de 64 bits.
Si utilizamos int puede dar fallos de compatibilidad.
*/
