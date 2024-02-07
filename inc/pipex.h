/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:37:10 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/07 17:28:30 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//libraries
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"

//error message macros
# define ERROR_ARG "Error: incorrect number of arguments\n"
# define ERROR_CMD "Command Error\n"
# define ERROR_EXE "Execve Error\n"
# define ERROR_FRK "Fork Error\n"
# define ERROR_INF "Infile Error\n"
# define ERROR_OUT "Outfile Error\n"
# define ERROR_PIP "Pipe Error\n"

//storage structure
typedef struct s_ppx
{
	int		infile_fd;
	int		outfile_fd;
	int		pipe_fd[2];
	char	*raw_cmd_paths;
	char	**cut_cmd_paths;
	pid_t	child_1_pid;
	pid_t	child_2_pid;
	char	**cmd_argv;
	char	*cmd_pathname;
}	t_ppx;

//pipex (main)
void	ppx_child_1(t_ppx ppx, char **argv, char **envp);
void	ppx_child_2(t_ppx ppx, char **argv, char **envp);
void	ppx_separated_at_birth(t_ppx ppx, char *argv[], char *envp[]);

//utils
char	*ppx_search_paths(char **envp);
char	*ppx_polish_cmd(char **cut_cmd_paths_aux, char *cmd_pathname);
void	ppx_close_pipe(t_ppx *ppx);
void	ppx_final_free(t_ppx *ppx);
void	ppx_exit_error(char *err);

#endif