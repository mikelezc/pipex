/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:34:43 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/08 18:46:12 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static void	create_pipes(t_bnsppx *bppx)
{
	int	i;

	i = 0;
	while (i < (bppx->cmd_nbs - 1))
	{
		if (pipe(bppx->end + 2 * i) < 0)
			free_parent(bppx);
		i++;
	}
}

void	close_ends(t_bnsppx *bppx)
{
	int	i;

	i = 0;
	while (i < (bppx->pipe_nbs))
	{
		close(bppx->end[i]);
		i++;
	}
}

/*void	leaks(void)
{
	system("leaks pipex_bonus");
}*/

int main(int argc, char **argv, char **envp)
{
	t_bnsppx	bppx;

	if (argc < args_eval(argv[1], &bppx))
		ppx_exit_error(ERROR_ARG);
	get_infile(argv, &bppx);
	get_outfile(argv[argc - 1], &bppx);
	bppx.cmd_nbs = argc - 3 - bppx.heredoc;
	bppx.pipe_nbs = 2 * (bppx.cmd_nbs - 1);
	bppx.end = (int *)malloc(sizeof(int) * bppx.pipe_nbs);
	if (!bppx.end)
		ppx_exit_error(ERROR_PIP);
	bppx.path = get_path(envp);
	bppx.cmd_paths = ft_split(bppx.path, ':');
	if (!bppx.cmd_paths)
		free_pipe(&bppx);
	create_pipes(&bppx);
	bppx.index = 0;
	while ((bppx.index) < bppx.cmd_nbs)
	{
		child(bppx, argv, envp);
		bppx.index++;
	}
	close_ends(&bppx);
	waitpid(-1, NULL, 0);
	//atexit(leaks);
	free_parent(&bppx);
	return (0);
}
