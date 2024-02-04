/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:39:02 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/28 21:26:51 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}

/*
Itera la lista ’lst’ y aplica la 
función ’f’ en el contenido de cada nodo.

Aplica una función a cada nodo de la lista.

lst: un puntero al primer nodo.
f: un puntero a la función que 
utilizará cada nodo.
*/