/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bppx_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:24:14 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/19 12:20:04 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

int	bppx_here_doc_create_tmp(void)
{
	int	tmp_fd;

	tmp_fd = open(".heredoc.temp", O_TRUNC | O_CREAT | O_WRONLY, 0000644);
	if (tmp_fd < 0)
	{
		close(tmp_fd);
		bppx_exit_error(ERROR_HRD);
	}
	return (tmp_fd);
}

void	bppx_here_doc(char *limiter)
{
	int		stdin_fd;
	char	*line;
	int		tmp_fd;

	tmp_fd = bppx_here_doc_create_tmp();
	line = NULL;
	stdin_fd = dup(STDIN_FILENO);
	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		line = get_next_line(stdin_fd);
		if (!line)
			break ;
		if (!ft_strncmp(limiter, line, ft_strlen(limiter + 1)))
		{
			close(stdin_fd);
			free (line);
			break ;
		}
		else
			ft_putstr_fd(line, tmp_fd);
		free(line);
	}
}
