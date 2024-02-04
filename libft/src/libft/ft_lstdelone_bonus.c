/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:57:46 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/28 21:24:47 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		(*del)(lst->content);
		free(lst);
	}
}

/*
Toma como parámetro un nodo ’lst’ y 
libera la memoria del contenido utilizando la 
función ’del’ dada como parámetro, además de liberar el nodo. 
La memoria de ’next’ no debe liberarse.

lst: el nodo a liberar.
del: un puntero a la función utilizada 
para liberar el contenido del nodo.
*/