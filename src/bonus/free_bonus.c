/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:27:26 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/09 12:53:26 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	free_parent(t_bnsppx *bppx)
{
	int	i;

	i = 0;
	close(bppx->infile);
	close(bppx->outfile);
	if (bppx->heredoc)
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

void	free_pipe(t_bnsppx *bppx)
{
	close(bppx->infile);
	close(bppx->outfile);
	if (bppx->heredoc)
		unlink(".heredoc.temp");
	free(bppx->end);
	ppx_exit_error(ERROR_ENV);
	exit(1);
}
