/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:53:14 by woosekim          #+#    #+#             */
/*   Updated: 2023/05/05 20:15:05 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handling(int num, char *cmd)
{
	char	*msg;

	if (num == 0)
	{
		msg = "zsh: command not found: ";
		write(2, msg, ft_strlen(msg));
		write(2, cmd, ft_strlen(cmd));
		write(2, "\n", 1);
		exit(1);
	}
	else if (num == 1)
	{
		msg = "zsh: no such file or directory: ";
		write(2, msg, ft_strlen(msg));
		write(2, cmd, ft_strlen(cmd));
		write(2, "\n", 1);
		exit(0);
	}
}

char	**find_path(char **env)
{
	char	*path;
	char	**path_split;
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			break ;
		i++;
	}
	path = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
	free(path);
	path_split = ft_split(path, ':');
	return (path_split);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != 0)
	{
		free(split[i]);
		i++;
	}
	free(split[i]);
	free(split);
}

char	**search_cmd(char **env, char *cmd, char **path, char *cmd_path)
{
	char	**cmd_arg;
	int		i;

	i = 0;
	path = find_path(env);
	cmd_arg = ft_split(cmd, ' ');
	cmd = ft_strjoin("/", cmd_arg[0]);
	while (path[i] != 0)
	{
		cmd_path = ft_strjoin(path[i], cmd);
		if (access(cmd_path, X_OK) == 0)
		{
			free(cmd);
			free(cmd_arg[0]);
			free_split(path);
			cmd_arg[0] = cmd_path;
			return (cmd_arg);
		}
		free(cmd_path);
		i++;
	}
	free(cmd);
	free_split(cmd_arg);
	free_split(path);
	return (0);
}
