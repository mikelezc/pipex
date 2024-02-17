/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bppx_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:48:12 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/17 12:29:32 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

char	*bppx_polish_cmd(char **cut_cmd_paths_aux, char *cmd_argv_name)
{
	char	*path_buffer;
	char	*cmd_buffer;

	while (*cut_cmd_paths_aux)
	{
		path_buffer = ft_strjoin(*cut_cmd_paths_aux, "/");
		cmd_buffer = ft_strjoin(path_buffer, cmd_argv_name);
		free(path_buffer);
		if (access(cmd_buffer, F_OK | X_OK) == 0)
			return (cmd_buffer);
		free(cmd_buffer);
		cut_cmd_paths_aux++;
	}
	return (NULL);
}

void	bppx_born_child(char **argv, char **envp, t_bnsppx bppx, int i)
{
	if (i == 0)
	{
		dup2 (bppx.infile_fd, STDIN_FILENO);
		dup2 (bppx.pipe_ends_fd[1], STDOUT_FILENO);
	}
	else if (i == bppx.cmd_amnt - 1)
	{
		dup2 (bppx.pipe_ends_fd[(i * 2) - 2], STDIN_FILENO);
		dup2 (bppx.outfile_fd, STDOUT_FILENO);
	}
	else
	{
		dup2 (bppx.pipe_ends_fd[(i * 2) - 2], STDIN_FILENO);
		dup2 (bppx.pipe_ends_fd[(i * 2) + 1], STDOUT_FILENO);
	}
	bppx_cut_pipes(&bppx);
	bppx.cmd_args = ft_split(argv[2 + bppx.here_doc + i], ' ');
	bppx.cmd = bppx_polish_cmd(bppx.cut_cmd_paths, bppx.cmd_args[0]);
	if (!bppx.cmd)
		bppx_free_child(&bppx);
	if (execve(bppx.cmd, bppx.cmd_args, envp) <= -1)
		bppx_exit_error(ERROR_EXE);
}

void	bppx_cmds(char **argv, char **envp, t_bnsppx bppx)
{
	int	i;

	i = -1;
	while (++i < bppx.cmd_amnt)
	{
		bppx.pid = fork();
		if (bppx.pid <= -1)
			bppx_exit_error(ERROR_FRK);
		else if (bppx.pid == 0)
			bppx_born_child(argv, envp, bppx, i);
	}
}

void	bppx_search_paths(char **envp, t_bnsppx *bppx)
{
	int	j;

	j = 0;
	while (ft_strncmp(envp[j], "PATH=", 5))
		j++;
	bppx->raw_cmd_paths = (envp[j] + 5);
	bppx->cut_cmd_paths = ft_split(bppx->raw_cmd_paths, ':');
	if (!bppx->cut_cmd_paths)
		bppx_free_pipe(bppx);
}
