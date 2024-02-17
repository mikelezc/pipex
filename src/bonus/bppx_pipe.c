/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bppx_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:47:11 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/17 11:45:25 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	bppx_cut_pipes(t_bnsppx *bppx)
{
	int	i;

	i = -1;
	while (++i < (bppx->pipe_ends_amnt))
		close(bppx->pipe_ends_fd[i]);
}

void	bppx_make_pipes(t_bnsppx *bppx)
{
	int	i;
	int	pipes_amnt;

	i = -1;
	while (++i < bppx->cmd_amnt - 1)
	{
		pipes_amnt = pipe(bppx->pipe_ends_fd + (i * 2));
		if (pipes_amnt < 0)
		{
			bppx_free_parent(bppx);
			bppx_exit_error(ERROR_PIP);
		}
	}
}
