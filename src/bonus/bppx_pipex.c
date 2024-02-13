/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bppx_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:34:43 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/13 21:17:36 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	bppx_make_pipes(t_bnsppx *bppx)
{
	int	i;
	int	pipes_amnt;

	i = -1;
	while (++i < bppx->cmd_amnt - 1)
	{
		pipes_amnt = pipe(bppx->pipe_ends_fd + 2 * i);
		if (pipes_amnt < 0)
		{
			bppx_free_parent(bppx);
			bppx_exit_error(ERROR_PIP);
		}
	}
}

void	bppx_cut_pipes(t_bnsppx *bppx)
{
	int	i;

	i = -1;
	while (++i < (bppx->pipe_ends_amnt))
		close(bppx->pipe_ends_fd[i]);
}

void	bppx_collect_paths(char **envp, t_bnsppx *bppx)
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	bppx->raw_cmd_paths = (envp[i] + 5);
	bppx->cut_cmd_paths = ft_split(bppx->raw_cmd_paths, ':');
	if (!bppx->cut_cmd_paths)
		bppx_free_pipe(bppx);
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
	int			i;

	i = -1;
	if (argc < bppx_valid_argc(argv[1], &bppx))
		bppx_exit_error(ERROR_ARG);
	bppx_fd_handling(argc, argv, &bppx);
	bppx_collect_paths(envp, &bppx);
	bppx_make_pipes(&bppx);
	while (++i < bppx.cmd_amnt)
		bppx_born_child(bppx, argv, envp, i);
	bppx_cut_pipes(&bppx);
	waitpid(-1, NULL, 0);
	bppx_free_parent(&bppx);
	return (0);
}
