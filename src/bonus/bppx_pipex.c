/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bppx_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:34:43 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/16 17:58:22 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

int	bppx_valid_argc(char *argv, t_bnsppx *bppx)
{
	if (ft_strncmp(argv, "here_doc", 8) == 0)
	{
		bppx->here_doc = 1;
		return (6);
	}
	else
	{
		bppx->here_doc = 0;
		return (5);
	}
}

void	leaks(void)
{
	system("leaks pipex_bonus");
	
}

int	main(int argc, char **argv, char **envp)
{
	t_bnsppx	bppx;

	if (argc < bppx_valid_argc(argv[1], &bppx))
		bppx_exit_error(ERROR_ARG);
	bppx_fd_handling(argc, argv, &bppx);
	bppx_make_pipes(&bppx);
	bppx_search_paths(envp, &bppx);
	bppx_cmds(envp, bppx, argv);
	bppx_cut_pipes(&bppx);
	waitpid(-1, NULL, 0);
	bppx_free_parent(&bppx);
	atexit(leaks);
	return (0);
}
