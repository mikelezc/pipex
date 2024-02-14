/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bppx_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:48:12 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/13 22:16:29 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

char	*bppx_polish_cmd(char **env_paths, char *cmd)
{
	char	*temp;
	char	*command;

	while (*env_paths)
	{
		temp = ft_strjoin(*env_paths, "/");
		command = ft_strjoin(temp, cmd);
		free(temp);
		if (access(command, F_OK | X_OK) == 0)
			return (command);
		free(command);
		env_paths++;
	}
	return (NULL);
}

void	bppx_dup2(int zero, int one)
{
	dup2 (zero, STDIN_FILENO);
	dup2 (one, STDOUT_FILENO);
}

void	bppx_born_child(t_bnsppx bppx, char **argv, char **envp, int i)
{
	bppx.pid = fork();
	if (bppx.pid < 0)
		bppx_exit_error(ERROR_FRK);
	else if (!bppx.pid)
	{
		if (i == 0)
			bppx_dup2(bppx.infile_fd, bppx.pipe_ends_fd[1]);
		else if (i == bppx.cmd_amnt - 1)
			bppx_dup2(bppx.pipe_ends_fd[2 * i - 2], bppx.outfile_fd);
		else
			bppx_dup2(bppx.pipe_ends_fd[2 * i - 2],
				bppx.pipe_ends_fd[2 * i + 1]);
		bppx_cut_pipes(&bppx);
		bppx.cmd_args = ft_split(argv[2 + bppx.here_doc + i], ' ');
		bppx.cmd = bppx_polish_cmd(bppx.cut_cmd_paths, bppx.cmd_args[0]);
		if (!bppx.cmd)
			bppx_free_child(&bppx);
		if (execve(bppx.cmd, bppx.cmd_args, envp) == -1)
			bppx_exit_error(ERROR_EXE);
	}
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
