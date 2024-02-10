/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bppx_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:48:48 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/10 18:04:37 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

int	bppx_is_here_doc(char *argv, t_bnsppx *bppx)
{
	if (ft_strncmp(argv, "here_doc", 8) == 0)
	{
		bppx->here_doc = 1;
		return (6);
	}
	else
	{
		bppx->here_doc = 0;
		return (5);
	}
}

void	bppx_here_doc(char *argv)
{
	int		temp_fd;
	int		stdin_fd;
	char	*line;

	temp_fd = open(".heredoc.temp", O_TRUNC | O_CREAT | O_WRONLY, 0000644);
	stdin_fd = dup(STDIN_FILENO);
	if (temp_fd < 0)
	{
		close(temp_fd);
		bppx_exit_error(ERROR_HRD);
	}
	line = NULL;
	while (1)
	{
		ft_putstr_fd("here_doc> ", 1);
		line = get_next_line(stdin_fd);
		if (line == NULL)
			break ;
		if (!ft_strncmp(argv, line, ft_strlen(argv + 1)))
			close(stdin_fd);
		else
			ft_putstr_fd(line, temp_fd);
		free(line);
	}
	close(temp_fd);
}
