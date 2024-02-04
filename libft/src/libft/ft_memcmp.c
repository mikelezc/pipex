/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:53:30 by mlezcano          #+#    #+#             */
/*   Updated: 2023/10/12 08:39:58 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)ptr1)[i] != ((unsigned char *)ptr2)[i])
			return ((((unsigned char *)ptr1)[i]) -
					(((unsigned char *)ptr2)[i]));
		i++;
	}
	return (0);
}
/*
Sirve para comparar los primeros n bytes de un area de memoria 
entre el string 1 y el string 2.

Si el valor de retorno es < 0 str1 es menor que str2.
Si el valor de retorno es > 0 str2 es menor que str1.
Si el valor de retorno es = 0 str1 es igual a str2.

*/
