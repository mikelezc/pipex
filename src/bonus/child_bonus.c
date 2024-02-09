/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:48:12 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/09 10:37:12 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

/*static char	*get_command(char **env_paths, char *cmd)
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
}*/

/*way to simplify dup2 process for child fxn, first 
repetition redirects to stdin & second rep redirects to stdout*/
static void	sub_dup2(int zero, int one)
{
	dup2 (zero, STDIN_FILENO);
	dup2 (one, STDOUT_FILENO);
}

/*Redirects file descriptor inputs and outputs (read & write ends) 
according to command index, then separates each component of each command 
using ft_split and searches the envp paths for the correct command path using
access() in get_command()*/
void	child(t_bnsppx bppx, char **argv, char **envp)
{
	bppx.pid = fork();

	if (bppx.pid < 0)
		ppx_exit_error(ERROR_FRK);
	else if (!bppx.pid)
	{
		if (bppx.index == 0)
			sub_dup2(bppx.infile, bppx.end[1]);
		else if (bppx.index == bppx.cmd_nbs - 1)
			sub_dup2(bppx.end[2 * bppx.index - 2], bppx.outfile);
		else
			sub_dup2(bppx.end[2 * bppx.index - 2],
				bppx.end[2 * bppx.index + 1]);
		close_ends(&bppx);
		bppx.cmd_args = ft_split(argv[2 + bppx.heredoc + bppx.index], ' ');
		bppx.cmd = get_command(bppx.cmd_paths, bppx.cmd_args[0]);
		if (!bppx.cmd)
		{
			free_child(&bppx);
			ppx_exit_error(ERROR_CMD);
		}
		if (execve(bppx.cmd, bppx.cmd_args, envp) == -1)
			ppx_exit_error(ERROR_EXE);
	}
}
