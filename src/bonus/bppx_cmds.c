/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bppx_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:48:12 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/17 12:16:00 by mlezcano         ###   ########.fr       */
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

void	bppx_dup2(int std_in, int std_out)
{
	dup2 (std_in, STDIN_FILENO);
	dup2 (std_out, STDOUT_FILENO);
}

void	bppx_born_child(char **argv, char **envp, t_bnsppx bppx, int i)
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
