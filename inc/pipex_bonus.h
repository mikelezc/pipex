/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:20:25 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/11 20:00:03 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
# define ERROR_CMD "Error: Command not found\n"
# define ERROR_EXE "Execve Error\n"
# define ERROR_FRK "Fork Error\n"
# define ERROR_INF "Infile Error\n"
# define ERROR_OUT "Outfile Error\n"
# define ERROR_PIP "Pipe Error\n"
# define ERROR_HRD "Here_doc Error\n"
# define ERROR_ENV "Enviroment Error\n"

//storage structure
typedef struct s_ppxbonus
{
	int		infile_fd;
	int		outfile_fd;
	int		here_doc;
	char	*raw_cmd_paths;
	char	**cut_cmd_paths;
	char	**cmd_args;
	char	*cmd;
	int		cmd_amnt;
	int		pipe_ends_amnt;
	int		*pipe_ends_fd;
	int		index;
	pid_t	pid;
}	t_bnsppx;

//bppx_pipex (main)
void	bppx_welding_pipes(t_bnsppx *bppx);
void	bppx_close_ends(t_bnsppx *bppx);
char	*bppx_search_paths(char **envp);
int		bppx_valid_argc(char *argv, t_bnsppx *bppx);

//bppx_fd_handling
void	bppx_outfile_fd(char *argv, t_bnsppx *bppx);
void	bppx_here_doc(char *argv);
void	bppx_infile_fd(char **argv, t_bnsppx *bppx);

//bppx_childs
void	bppx_dup2(int zero, int one);
char	*bppx_polish_cmd(char **env_paths, char *cmd);
void	bppx_born_child(t_bnsppx bppx, char **argv, char **envp);

//bppx_ends
void	bppx_exit_error(char *err);
void	bppx_final_pipe(t_bnsppx *bppx);
void	bppx_final_child(t_bnsppx *bppx);
void	bppx_final_parent(t_bnsppx *bppx);

#endif