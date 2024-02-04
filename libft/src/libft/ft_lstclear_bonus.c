/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:14:57 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/28 21:26:34 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*advance;

	advance = NULL;
	while (*lst)
	{
		advance = (*lst)->next;
		(del)((*lst)->content);
		free(*lst);
		(*lst) = advance;
	}
}

/*
Elimina y libera el nodo ’lst’ dado 
y todos los consecutivos de ese nodo, 
utilizando la función ’del’ y free(3).
Al final, el puntero a la lista debe ser NULL.

Es decir: Elimina y libera todos los nodos de la lista.

lst: la dirección de un puntero a un nodo.
del: un puntero a función utilizado para 
eliminar el contenido de un nodo.

*/