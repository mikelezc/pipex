/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:37:39 by mlezcano          #+#    #+#             */
/*   Updated: 2023/09/14 15:24:54 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*Función para determinar si el carácter introducido, 
 es un carácter imprimible(incluyendo espacio).
Usamos el return para poner la condición en él, 
y que retorne 1 en caso de ser verdadera*/
