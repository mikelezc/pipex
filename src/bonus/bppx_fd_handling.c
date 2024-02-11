/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bppx_in_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:05:33 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/11 18:51:33 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	bppx_outfile_fd(char *argv, t_bnsppx *bppx)
{
	if (bppx->here_doc)
		bppx->outfile_fd = open(argv, O_APPEND | O_CREAT | O_WRONLY, 0644);
	else
		bppx->outfile_fd = open(argv, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (bppx->outfile_fd < 0)
		bppx_exit_error(ERROR_OUT);
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

void	bppx_infile_fd(char **argv, t_bnsppx *bppx)
{
	if (bppx->here_doc)
	{
		bppx_here_doc(argv[2]);
		bppx->infile_fd = open(".heredoc.temp", O_RDONLY);
		if (bppx->infile_fd < 0)
		{
			unlink(".heredoc.temp");
			bppx_exit_error(ERROR_HRD);
		}
	}
	else
	{
		bppx->infile_fd = open(argv[1], O_RDONLY);
		if (bppx->infile_fd < 0)
			bppx_exit_error(ERROR_INF);
	}
}
