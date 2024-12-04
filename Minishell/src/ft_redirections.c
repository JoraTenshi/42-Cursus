/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:36:51 by jcallejo          #+#    #+#             */
/*   Updated: 2024/11/28 18:30:43 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_in_redir(t_data *data, t_redir *redir)
{
	int		fd;

	fd = 0;
	if (redir->type == HEREDOC)
		ft_heredoc(data, redir);
	if (redir->type == INPUT_REDIRECT)
	{
		fd = open(redir->file, O_RDONLY);
		if (fd < 1)
			return (perror("open"));
		dup2(fd, STDIN_FILENO);
	}
	close(fd);
}

void	ft_out_redir(t_redir *redir)
{
	int		fd;

	fd = 0;
	if (redir->type == OUTPUT_REDIRECT)
	{
		fd = open(redir->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 1)
			return (perror("open"));
		dup2(fd, STDOUT_FILENO);
	}
	if (redir->type == OUTPUT_APPEND)
	{
		fd = open(redir->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd < 1)
			return (perror("open"));
		dup2(fd, STDOUT_FILENO);
	}
	close(fd);
}
