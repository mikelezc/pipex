/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:31:06 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/28 21:25:33 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*fwd_lst;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		fwd_lst = ft_lstlast(*lst);
		fwd_lst->next = new;
	}
}

/*
Añade el nodo ’new’ al final de la lista ’lst’

lst: el puntero al primer nodo de una lista. 
new: el puntero a un nodo que añadir a la lista.

return vacío es para que si no se cumple la condición 
te retorne sin ejecutar más código

* fwd_lst es un noso que declaramos para avanzar 
por la lista hasta llegar al final.

Recuerda:
ft_lstlast: Devuelve el último nodo de la lista.
*/