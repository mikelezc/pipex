/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:53:54 by mlezcano          #+#    #+#             */
/*   Updated: 2023/10/12 08:41:17 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *string, const char *match, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (match[0] == '\0')
		return ((char *)string);
	while (string[h] != '\0')
	{
		n = 0;
		while (string[h + n] == match[n] && (h + n) < len)
		{
			if (string [h + n] == '\0' && match[n] == '\0')
				return ((char *)&string[h]);
			n++;
		}
		if (match[n] == '\0')
			return ((char *)string + h);
		h++;
	}
	return (0);
}
