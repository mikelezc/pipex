/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 08:13:44 by mlezcano          #+#    #+#             */
/*   Updated: 2023/10/12 10:26:33 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	ft_putcharl(char a, int *length);
void	ft_putstrl(char *str, int *length);
void	ft_putnbrl(int nbr, int *length);
void	ft_puthexal(unsigned long long nbr, char *base, int	*length);
void	ft_putunsl(unsigned int num, int *len);

#endif