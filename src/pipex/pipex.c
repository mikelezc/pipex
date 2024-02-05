/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:23:34 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/05 21:34:03 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child1(t_ppx ppx, char **argv, char **envp)
{
	int	i;

	i = 0;
	dup2(ppx.end[1], STDOUT_FILENO);
	close(ppx.end[0]);
	dup2(ppx.infile, STDIN_FILENO);
	ppx.cmd_args = ft_split(argv[2], ' ');
	ppx.cmd = get_command(ppx.cmd_paths, ppx.cmd_args[0]);
	if (!ppx.cmd)
	{
		while (ppx.cmd_args[i])
			free(ppx.cmd_args[i++]);
		free(ppx.cmd_args);
		free(ppx.cmd);
		ppx_error(CMD);
	}
	if (execve(ppx.cmd, ppx.cmd_args, envp) == -1)
		ppx_error(EXECVE);
}

void	child2(t_ppx ppx, char **argv, char **envp)
{
	int	i;

	i = 0;
	dup2(ppx.end[0], STDIN_FILENO);
	close(ppx.end[1]);
	dup2(ppx.outfile, STDOUT_FILENO);
	ppx.cmd_args = ft_split(argv[3], ' ');
	ppx.cmd = get_command(ppx.cmd_paths, ppx.cmd_args[0]);
	if (!ppx.cmd)
	{
		while (ppx.cmd_args[i])
			free(ppx.cmd_args[i++]);
		free(ppx.cmd_args);
		free(ppx.cmd);
		ppx_error(CMD);
	}
	if (execve(ppx.cmd, ppx.cmd_args, envp) == -1)
		ppx_error(EXECVE);
}

void	exec_children(t_ppx ppx, char *argv[], char *envp[])
{
	ppx.pid1 = fork();
	if (ppx.pid1 < 0)
		ppx_error(FORK);
	else if (ppx.pid1 == 0)
		child1(ppx, argv, envp);
	ppx.pid2 = fork();
	if (ppx.pid2 < 0)
		ppx_error(FORK);
	else if (ppx.pid2 == 0)
		child2(ppx, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_ppx	ppx;

	if (argc == 5)
	{
		ppx.infile = open(argv[1], O_RDONLY);
		if (ppx.infile < 0)
			ppx_error(INFILE);
		ppx.outfile = open(argv[4], O_TRUNC | O_RDWR | O_CREAT, 0644);
		if (ppx.outfile < 0)
			ppx_error(OUTFILE);
		if (pipe(ppx.end) < 0)
			ppx_error(PIPE);
		ppx.path = get_path(envp);
		ppx.cmd_paths = ft_split(ppx.path, ':');
		exec_children(ppx, argv, envp);
		close_ends(&ppx);
		waitpid(ppx.pid1, NULL, 0);
		waitpid(ppx.pid2, NULL, 0);
		free_parent(&ppx);
	}
	else
		ft_putstr_fd(ARGC, 2);
	return (0);
}
