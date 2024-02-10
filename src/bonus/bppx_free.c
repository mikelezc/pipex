/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bppx_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:27:26 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/10 13:24:50 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	bppx_final_parent(t_bnsppx *bppx)
{
	int	i;

	i = 0;
	close(bppx->infile_fd);
	close(bppx->outfile_fd);
	if (bppx->here_doc)
		unlink(".heredoc.temp");
	while (bppx->cmd_paths[i])
	{
		free(bppx->cmd_paths[i]);
		i++;
	}
	free(bppx->cmd_paths);
	free(bppx->end);
}

void	free_child(t_bnsppx *bppx)
{
	int	i;

	i = 0;
	while (bppx->cmd_args[i])
		free(bppx->cmd_args[i++]);
	free(bppx->cmd_args);
	free(bppx->cmd);
}

void	bppx_final_pipe(t_bnsppx *bppx)
{
	close(bppx->infile_fd);
	close(bppx->outfile_fd);
	if (bppx->here_doc)
		unlink(".heredoc.temp");
	free(bppx->end);
	bppx_exit_error(ERROR_ENV);
	exit(1);
}
