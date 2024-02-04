/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:46:38 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/28 21:26:12 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newl;
	t_list	*newn;
	void	*content;

	newl = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&newl, del);
			return (NULL);
		}
		newn = ft_lstnew(content);
		if (!newn)
		{
			del(content);
			ft_lstclear(&newl, del);
			return (NULL);
		}
		ft_lstadd_back(&newl, newn);
		lst = lst->next;
	}
	return (newl);
}

/*
Itera la lista ’lst’ y aplica la función ’f’ 
al contenido de cada nodo. 
Crea una lista resultante de la aplicación correcta 
y sucesiva de la función ’f’ sobre cada nodo. 
La función ’del’ se utiliza para eliminar 
el contenido de un nodo, si hace falta.

Aplica una función a cada nodo de la lista 
y crea una nueva lista resultante.

lst: un puntero a un nodo.
f: la dirección de un puntero a una función usada en 
la iteración de cada elemento de la lista. 
del: un puntero a función utilizado para eliminar 
el contenido de un nodo, si es necesario.

Retorna:
La nueva lista.
NULL si falla la reserva de memoria.
*/