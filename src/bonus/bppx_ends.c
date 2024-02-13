/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bppx_ends.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:27:26 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/13 11:31:40 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	bppx_exit_error(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}

void	bppx_free_parent(t_bnsppx *bppx)
{
	int	i;

	i = -1;
	close(bppx->infile_fd);
	close(bppx->outfile_fd);
	if (bppx->here_doc)
		unlink(".heredoc.temp");
	while (bppx->cut_cmd_paths[++i])
		free(bppx->cut_cmd_paths[i]);
	free(bppx->cut_cmd_paths);
	free(bppx->pipe_ends_fd);
}

void	bppx_free_child(t_bnsppx *bppx)
{
	int	i;

	i = -1;
	while (bppx->cmd_args[++i])
		free(bppx->cmd_args[i]);
	free(bppx->cmd_args);
	free(bppx->cmd);
	bppx_exit_error(ERROR_CMD);
}

void	bppx_free_pipe(t_bnsppx *bppx)
{
	close(bppx->infile_fd);
	close(bppx->outfile_fd);
	if (bppx->here_doc)
		unlink(".heredoc.temp");
	free(bppx->pipe_ends_fd);
	bppx_exit_error(ERROR_ENV);
}
