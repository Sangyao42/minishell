/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:49:02 by htsang            #+#    #+#             */
/*   Updated: 2023/06/21 15:24:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "MINISHELL/execution/executor/enactment.h"
#include "LIBFT/string.h"
#include "LIBFT/iostream.h"

static t_executor_exit_code	ms_executor_enact_heredoc(\
struct s_ms_executor *executor, struct s_ast_redirection *redirection)
{
	int					read_status;
	t_ft_string_slice	slice;

	if ((ms_executor_redirect_from_heredoc() == EXECUTION_ERROR))
		return (EXECUTION_ERROR);
	ft_iostream_reset(&executor->iostream);
	read_status = ft_iostream_read_until(&executor->iostream, \
		executor->stdin_fd, "\n");
	while (read_status != -1)
	{
		slice = ft_iostream_to_slice(&executor->iostream);
		if (ft_strncmp(ft_string_slice_content(&slice), \
			redirection->content.buffer, slice.size) == 0)
			break ;
		ft_string_slice_print(slice, STDIN_FILENO);
		write(STDIN_FILENO, "\n", 1);
		ft_iostream_reset(&executor->iostream);
		read_status = ft_iostream_read_until(&executor->iostream, \
			executor->stdin_fd, "\n");
	}
	return (EXECUTION_SUCCESS);
}

t_executor_exit_code	ms_executor_enact_redirection_in(\
struct s_ms_executor *executor, t_ast_redirection_vector *redirection_in)
{
	t_ft_vector_iterator		iterator;
	struct s_ast_redirection	*redirection;

	ft_vector_iterator_init(&iterator, redirection_in);
	while (!ft_vector_iterator_is_end(&iterator))
	{
		redirection = ft_vector_iterator_current(&iterator);
		if (redirection->type == REDIRECT_HEREDOC)
		{
			if (ms_executor_enact_heredoc(executor, redirection) \
				== EXECUTION_ERROR)
				return (EXECUTION_ERROR);
		}
		else if (redirection->type == REDIRCT_STDIN)
		{
			if (ms_executor_redirect_from_file(redirection->content.buffer, \
					O_RDONLY) == EXECUTION_ERROR)
				return (EXECUTION_ERROR);
		}
		ft_vector_iterator_next(&iterator);
	}
	return (EXECUTION_SUCCESS);
}

t_executor_exit_code	ms_executor_enact_redirection_out(\
t_ast_redirection_vector *redirection_out)
{
	t_ft_vector_iterator		iterator;
	struct s_ast_redirection	*redirection;

	ft_vector_iterator_init(&iterator, redirection_out);
	while (!ft_vector_iterator_is_end(&iterator))
	{
		redirection = ft_vector_iterator_current(&iterator);
		if (redirection->type == REDIRECT_STDOUT)
		{
			if (ms_executor_redirect_to_file(redirection->content.buffer, \
					O_WRONLY | O_CREAT | O_TRUNC) == EXECUTION_ERROR)
				return (EXECUTION_ERROR);
		}
		else if (redirection->type == REDIRECT_STDOUT_APPEND)
		{
			if (ms_executor_redirect_to_file(redirection->content.buffer, \
					O_WRONLY | O_CREAT | O_APPEND) == EXECUTION_ERROR)
				return (EXECUTION_ERROR);
		}
		ft_vector_iterator_next(&iterator);
	}
	return (EXECUTION_SUCCESS);
}
