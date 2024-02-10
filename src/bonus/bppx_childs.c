/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bppx_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:48:12 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/10 13:24:37 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	bppx_dup2(int zero, int one)
{
	dup2 (zero, STDIN_FILENO);
	dup2 (one, STDOUT_FILENO);
}

void	bppx_born_child(t_bnsppx bppx, char **argv, char **envp)
{
	bppx.pid = fork();
	if (bppx.pid < 0)
		bppx_exit_error(ERROR_FRK);
	else if (!bppx.pid)
	{
		if (bppx.index == 0)
			bppx_dup2(bppx.infile_fd, bppx.end[1]);
		else if (bppx.index == bppx.cmd_nbs - 1)
			bppx_dup2(bppx.end[2 * bppx.index - 2], bppx.outfile_fd);
		else
			bppx_dup2(bppx.end[2 * bppx.index - 2],
				bppx.end[2 * bppx.index + 1]);
		bppx_close_end(&bppx);
		bppx.cmd_args = ft_split(argv[2 + bppx.here_doc + bppx.index], ' ');
		bppx.cmd = get_command(bppx.cmd_paths, bppx.cmd_args[0]);
		if (!bppx.cmd)
		{
			free_child(&bppx);
			bppx_exit_error(ERROR_CMD);
		}
		if (execve(bppx.cmd, bppx.cmd_args, envp) == -1)
			bppx_exit_error(ERROR_EXE);
	}
}
