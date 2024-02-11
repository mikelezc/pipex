/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bppx_childs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:48:12 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/11 19:59:53 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	bppx_dup2(int zero, int one)
{
	dup2 (zero, STDIN_FILENO);
	dup2 (one, STDOUT_FILENO);
}

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

void	bppx_born_child(t_bnsppx bppx, char **argv, char **envp)
{
	bppx.pid = fork();
	if (bppx.pid < 0)
		bppx_exit_error(ERROR_FRK);
	else if (!bppx.pid)
	{
		if (bppx.index == 0)
			bppx_dup2(bppx.infile_fd, bppx.pipe_ends_fd[1]);
		else if (bppx.index == bppx.cmd_amnt - 1)
			bppx_dup2(bppx.pipe_ends_fd[2 * bppx.index - 2], bppx.outfile_fd);
		else
			bppx_dup2(bppx.pipe_ends_fd[2 * bppx.index - 2],
				bppx.pipe_ends_fd[2 * bppx.index + 1]);
		bppx_close_ends(&bppx);
		bppx.cmd_args = ft_split(argv[2 + bppx.here_doc + bppx.index], ' ');
		bppx.cmd = bppx_polish_cmd(bppx.cut_cmd_paths, bppx.cmd_args[0]);
		if (!bppx.cmd)
			bppx_final_child(&bppx);
		if (execve(bppx.cmd, bppx.cmd_args, envp) == -1)
			bppx_exit_error(ERROR_EXE);
	}
}
