/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:57:05 by woosekim          #+#    #+#             */
/*   Updated: 2023/05/05 19:16:34 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

char	**find_path(char **env);
char	**search_cmd(char **env, char *cmd, char **path, char *cmd_path);
void	error_handling(int num, char *cmd);
void	free_split(char **split);

#endif
