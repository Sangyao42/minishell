/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:24:47 by htsang            #+#    #+#             */
/*   Updated: 2023/06/26 02:36:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include "MINISHELL/parser/ast.h"
# include "MINISHELL/execution/vars.h"
# include "MINISHELL/execution/executor.h"

struct s_ms
{
	struct s_ms_vars		vars;
	struct s_ms_executor	executor;
	struct s_ast_node		*ast_root;
	char					*line;
};

int				ms_init(struct s_ms *ms);

void			ms_reset(struct s_ms *ms);

t_ms_exit_code	ms_interpret(struct s_ms *ms, char *line);

void			ms_free(struct s_ms *ms);

bool			ms_line_is_empty(char *line);

int				ms_exit_code_save(struct s_ms *ms, t_ms_exit_code exit_code);

int				ms_terminal_settings_change(void);

int				ms_terminal_settings_restore(void);

#endif