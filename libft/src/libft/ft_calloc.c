/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:54:35 by mlezcano          #+#    #+#             */
/*   Updated: 2023/09/19 18:04:17 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*pnt;

	pnt = malloc(nitems * size);
	if (pnt == 0)
		return (pnt);
	ft_bzero(pnt, nitems * size);
	return (pnt);
}

/*
Sirve para localizar una dirección de memoria,
de tal forma que devuelve un puntero a la dirección solicitada. 
La diferencia entre malloc y calloc es que malloc no
resetea la memoria a cero y calloc lo hace.

nitems − número de elementos a localizar.

size − tamaño de los elementos.
*/
