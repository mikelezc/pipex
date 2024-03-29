/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:23:25 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/16 19:03:49 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*ppx_search_paths(char **envp)
{
	int	j;

	j = -1;
	while (envp[++j])
	{
		if (ft_strncmp(envp[j], "PATH=", 5) == 0)
			return (envp[j] + 5);
	}
	return (NULL);
}

char	*ppx_polish_cmd(char **cut_cmd_paths_aux, char *cmd_argv_name)
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

void	ppx_final_free(t_ppx *ppx)
{
	int	i;

	i = -1;
	close(ppx->infile_fd);
	close(ppx->outfile_fd);
	while (ppx->cut_cmd_paths[++i])
		free(ppx->cut_cmd_paths[i]);
	free(ppx->cut_cmd_paths);
}

void	ppx_exit_error(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}
