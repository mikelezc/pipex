/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:23:34 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/14 15:44:16 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ppx_child_1(t_ppx ppx, char **argv, char **envp)
{
	int	i;

	i = -1;
	dup2(ppx.pipe_fd[1], STDOUT_FILENO);
	close(ppx.pipe_fd[0]);
	dup2(ppx.infile_fd, STDIN_FILENO);
	ppx.cmd_argv = ft_split(argv[2], ' ');
	ppx.cmd_pathname = ppx_polish_cmd(ppx.cut_cmd_paths, ppx.cmd_argv[0]);
	if (!ppx.cmd_pathname)
	{
		while (ppx.cmd_argv[++i])
			free(ppx.cmd_argv[i]);
		free(ppx.cmd_argv);
		free(ppx.cmd_pathname);
		ppx_exit_error(ERROR_CMD);
	}
	if (execve(ppx.cmd_pathname, ppx.cmd_argv, envp) <= -1)
		ppx_exit_error(ERROR_EXE);
}

void	ppx_child_2(t_ppx ppx, char **argv, char **envp)
{
	int	i;

	i = -1;
	dup2(ppx.pipe_fd[0], STDIN_FILENO);
	close(ppx.pipe_fd[1]);
	dup2(ppx.outfile_fd, STDOUT_FILENO);
	ppx.cmd_argv = ft_split(argv[3], ' ');
	ppx.cmd_pathname = ppx_polish_cmd(ppx.cut_cmd_paths, ppx.cmd_argv[0]);
	if (!ppx.cmd_pathname)
	{
		while (ppx.cmd_argv[++i])
			free(ppx.cmd_argv[i]);
		free(ppx.cmd_argv);
		free(ppx.cmd_pathname);
		ppx_exit_error(ERROR_CMD);
	}
	if (execve(ppx.cmd_pathname, ppx.cmd_argv, envp) <= -1)
		ppx_exit_error(ERROR_EXE);
}

void	ppx_cmds(t_ppx ppx, char **argv, char **envp)
{
	ppx.child_1_pid = fork();
	if (ppx.child_1_pid <= -1)
		ppx_exit_error(ERROR_FRK);
	else if (ppx.child_1_pid == 0)
		ppx_child_1(ppx, argv, envp);
	ppx.child_2_pid = fork();
	if (ppx.child_2_pid <= -1)
		ppx_exit_error(ERROR_FRK);
	else if (ppx.child_2_pid == 0)
		ppx_child_2(ppx, argv, envp);
}

void	ppx_fd_handling(char **argv, t_ppx *ppx)
{
	ppx->infile_fd = open(argv[1], O_RDONLY);
	if (ppx->infile_fd <= -1)
		ppx_exit_error(ERROR_INF);
	if (pipe(ppx->pipe_fd) <= -1)
		ppx_exit_error(ERROR_PIP);
	ppx->outfile_fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (ppx->outfile_fd <= -1)
		ppx_exit_error(ERROR_OUT);
}

int	main(int argc, char **argv, char **envp)
{
	t_ppx	ppx;

	if (argc != 5)
		ppx_exit_error(ERROR_ARG);
	ppx_fd_handling(argv, &ppx);
	ppx.raw_cmd_paths = ppx_search_paths(envp);
	ppx.cut_cmd_paths = ft_split(ppx.raw_cmd_paths, ':');
	ppx_cmds(ppx, argv, envp);
	ppx_close_pipe(&ppx);
	waitpid(ppx.child_1_pid, NULL, 0);
	waitpid(ppx.child_2_pid, NULL, 0);
	ppx_final_free(&ppx);
	return (0);
}
