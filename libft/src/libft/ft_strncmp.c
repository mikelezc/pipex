/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:52:46 by mlezcano          #+#    #+#             */
/*   Updated: 2023/10/12 08:41:12 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;
	unsigned int	res;

	count = 0;
	res = 0;
	while ((count < n) && !res && (s1[count] != 0) && (s2[count] != 0))
	{
		res = (unsigned char)s1[count] - (unsigned char)s2[count];
		count++;
	}
	if (count < n && !res && (s1[count] == 0 || s2[count] == 0))
		res = (unsigned char)s1[count] - (unsigned char)s2[count];
	return (res);
}
