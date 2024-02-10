/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bppx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:34:43 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/10 12:17:48 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	bppx_welding_pipes(t_bnsppx *bppx)
{
	int	i;

	i = 0;
	while (i < (bppx->cmd_nbs - 1))
	{
		if (pipe(bppx->end + 2 * i) < 0)
			bppx_final_parent(bppx);
		i++;
	}
}

void	bppx_close_end(t_bnsppx *bppx)
{
	int	i;

	i = 0;
	while (i < (bppx->pipe_nbs))
	{
		close(bppx->end[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_bnsppx	bppx;

	if (argc < bppx_is_here_doc(argv[1], &bppx))
		bppx_exit_error(ERROR_ARG);
	bppx_infile_fd(argv, &bppx);
	bppx_outfile_fd(argv[argc - 1], &bppx);
	bppx.cmd_nbs = argc - 3 - bppx.here_doc;
	bppx.pipe_nbs = 2 * (bppx.cmd_nbs - 1);
	bppx.end = (int *)malloc(sizeof(int) * bppx.pipe_nbs);
	if (!bppx.end)
		bppx_exit_error(ERROR_PIP);
	bppx.path = bppx_search_paths(envp);
	bppx.cmd_paths = ft_split(bppx.path, ':');
	if (!bppx.cmd_paths)
		bppx_final_pipe(&bppx);
	bppx_welding_pipes(&bppx);
	bppx.index = 0;
	while ((bppx.index) < bppx.cmd_nbs)
	{
		bppx_born_child(bppx, argv, envp);
		bppx.index++;
	}
	bppx_close_end(&bppx);
	waitpid(-1, NULL, 0);
	bppx_final_parent(&bppx);
}
