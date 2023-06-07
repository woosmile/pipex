/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:56:48 by woosekim          #+#    #+#             */
/*   Updated: 2023/05/05 20:21:03 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char *filename, char **cmd, int *fds)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_handling(1, filename);
	dup2(fd, 0);
	dup2(fds[1], 1);
	close(fds[0]);
	close(fds[1]);
	execve(cmd[0], cmd, NULL);
	free_split(cmd);
}

void	parent(char *filename, char **cmd, int *fds)
{
	pid_t	pid;
	int		fd_out;

	pid = fork();
	if (pid == 0)
	{
		dup2(fds[0], 0);
		close(fds[0]);
		close(fds[1]);
		fd_out = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		dup2(fd_out, 1);
		execve(cmd[0], cmd, NULL);
		free_split(cmd);
	}
	else if (pid > 0)
	{
		close(fds[0]);
		close(fds[1]);
		free_split(cmd);
	}
}

int	main(int ac, char **av, char **env)
{
	int		fds[2];
	char	**cmd;
	pid_t	pid;

	if (ac > 4)
	{
		cmd = search_cmd(env, av[2], NULL, NULL);
		if (cmd == NULL)
			error_handling(0, av[2]);
		pipe(fds);
		pid = fork();
		if (pid == 0)
			child(av[1], cmd, fds);
		else if (pid > 0)
		{
			free_split(cmd);
			cmd = search_cmd(env, av[3], NULL, NULL);
			if (cmd == NULL)
				error_handling(0, av[3]);
			parent(av[4], cmd, fds);
		}
	}
	return (0);
}
