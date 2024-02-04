/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:38:25 by mlezcano          #+#    #+#             */
/*   Updated: 2023/10/28 19:33:48 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>	
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*gnl_strchr(const char *word, char chr);
char	*gnl_strjoin(char *s1, char *s2);
size_t	ft_strlen(char const *word);
char	*get_next_line(int fd);
char	*gnl_traincontainer(int fd, char *container);
char	*gnl_surplus(char *container);
char	*gnl_polish(char *container);

#endif
