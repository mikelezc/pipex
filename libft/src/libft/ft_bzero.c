/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:39:26 by mlezcano          #+#    #+#             */
/*   Updated: 2023/10/02 17:35:59 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		*(str + i) = 0;
		i++;
	}
}
/*
Sirve para escribir 0 en los bytes del string s.
Si n es igual a cero, esta función no hace nada.

unsigned int    i; //positivos porque vamos a iterar en bytes
char    *str_c; //se trata como caracter porque llenaremos con '\0'
*/
