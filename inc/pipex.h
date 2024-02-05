/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:37:10 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/05 22:29:14 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"

//error message macros
# define ARGC "Error: incorrect number of arguments\n"
# define CMD "Command Error\n"
# define EXECVE "Execve Error\n"
# define FORK "Fork Error\n"
# define INFILE "Infile Error\n"
# define OUTFILE "Outfile Error\n"
# define PIPE "Pipe Error\n"

//storage structure
typedef struct s_ppx
{
	int		infile;
	int		outfile;
	int		end[2];
	char	*path;
	char	**cmd_paths;
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd_args;
	char	*cmd;
}	t_ppx;

//pipex (main)
void	child1(t_ppx ppx, char **argv, char **envp);
void	child2(t_ppx ppx, char **argv, char **envp);
void	exec_children(t_ppx ppx, char *argv[], char *envp[]);

//utils
char	*get_path(char **envp);
char	*get_command(char **env_paths, char *cmd);
void	free_parent(t_ppx *ppx);
void	close_ends(t_ppx *ppx);
void	ppx_error(char *err);

#endif