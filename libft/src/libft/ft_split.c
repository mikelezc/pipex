/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:02:15 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/28 14:19:27 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	listsize;
	size_t	i;

	i = 0;
	listsize = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c)
			|| (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			listsize++;
		i++;
	}
	return (listsize);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char			*buffer;
	unsigned int	i;

	i = 0;
	if (ft_strlen(s) <= n)
		n = ft_strlen(s);
	buffer = malloc(sizeof(char) * (n + 1));
	if (buffer == NULL)
		return (NULL);
	while (i < n)
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static char	**ft_freeall(char **list)
{
	size_t	j;

	j = 0;
	while (list[j])
	{
		free(list[j]);
		j++;
	}
	free(list);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strlist;
	size_t	wc;
	size_t	recos;
	size_t	save;

	wc = 0;
	recos = 0;
	strlist = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!strlist)
		return (NULL);
	while (wc < ft_wordcount(s, c) && s[recos] != '\0')
	{
		while (s[recos] == c)
			recos++;
		save = recos;
		while (s[recos] != c && s[recos] != '\0')
			recos++;
		strlist[wc] = ft_strndup(&s[save], recos - save);
		if (strlist[wc++] == 0)
			return (ft_freeall(strlist));
	}
	strlist[wc] = NULL;
	return (strlist);
}

/*
Reserva (utilizando malloc(3)) un array de strings 
resultante de separar la string ’s’ en substrings utilizando 
el caracter ’c’ como delimitador. 
El array debe terminar con un puntero NULL.

- Parámetros:
s: La string a separar.
c: El carácter delimitador.

- Nos tiene que devolver:

El array de nuevas strings resulatente de la separación.
NULL si falla la reserva de memoria.

*/
