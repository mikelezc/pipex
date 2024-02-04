/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:04:19 by mlezcano          #+#    #+#             */
/*   Updated: 2023/09/26 14:20:06 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->next = NULL;
	new->content = content;
	return (new);
}

/*
Crea un nuevo nodo utilizando malloc(3). 
La variable miembro ’content’ se inicializa con el 
contenido del parámetro ’content’. La variable ’next’, con NULL.

content: el contenido con el que crear el nodo.
*/
