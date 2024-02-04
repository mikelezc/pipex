/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:50:41 by mlezcano          #+#    #+#             */
/*   Updated: 2023/09/25 14:53:01 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;
	int		j;

	j = 0;
	if (s && f)
	{
		i = ft_strlen(s);
		while (j < i)
		{
			(f)(j, s);
			s++;
			j++;
		}
	}
}
/*
int main() {
    char str[] = "Hello, World!";

    void print_char_index(unsigned int index, char *c)
	{
		printf("Carácter en el índice %u: %c\n", index, *c);
    }

    ft_striteri(str, print_char_index);

    return 0;
}*/
/*
A cada carácter de la string ’s’, aplica la función ’f’ 
dando como parámetros el índice de cada carácter dentro de ’s’ 
y la dirección del propio carácter, que podrá modificarse si es necesario.

Parámetros:
s: La string que iterar.
f: La función a aplicar sobre cada carácter.
*/