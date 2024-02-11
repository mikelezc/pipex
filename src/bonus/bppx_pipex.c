/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bppx_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:34:43 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/11 19:58:11 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	bppx_welding_pipes(t_bnsppx *bppx)
{
	int	i;

	i = 0;
	while (i < (bppx->cmd_amnt - 1))
	{
		if (pipe(bppx->pipe_ends_fd + 2 * i) < 0)
		{
			bppx_final_parent(bppx);
			bppx_exit_error(ERROR_PIP);
		}
		i++;
	}
}

void	bppx_close_ends(t_bnsppx *bppx)
{
	int	i;

	i = 0;
	while (i < (bppx->pipe_ends_amnt))
	{
		close(bppx->pipe_ends_fd[i]);
		i++;
	}
}

char	*bppx_search_paths(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	return (envp[i] + 5);
}

int	bppx_valid_argc(char *argv, t_bnsppx *bppx)
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

int	main(int argc, char **argv, char **envp)
{
	t_bnsppx	bppx;

	if (argc < bppx_valid_argc(argv[1], &bppx))
		bppx_exit_error(ERROR_ARG);
	bppx_infile_fd(argv, &bppx);
	bppx_outfile_fd(argv[argc - 1], &bppx);
	bppx.cmd_amnt = argc - 3 - bppx.here_doc;
	bppx.pipe_ends_amnt = 2 * (bppx.cmd_amnt - 1);
	bppx.pipe_ends_fd = (int *)malloc(sizeof(int) * bppx.pipe_ends_amnt);
	if (!bppx.pipe_ends_fd)
		bppx_exit_error(ERROR_PIP);
	bppx.raw_cmd_paths = bppx_search_paths(envp);
	bppx.cut_cmd_paths = ft_split(bppx.raw_cmd_paths, ':');
	if (!bppx.cut_cmd_paths)
		bppx_final_pipe(&bppx);
	bppx_welding_pipes(&bppx);
	bppx.index = 0;
	while ((bppx.index) < bppx.cmd_amnt)
	{
		bppx_born_child(bppx, argv, envp);
		bppx.index++;
	}
	bppx_close_ends(&bppx);
	waitpid(-1, NULL, 0);
	bppx_final_parent(&bppx);
}
