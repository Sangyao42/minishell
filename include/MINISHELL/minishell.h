/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:24:47 by htsang            #+#    #+#             */
/*   Updated: 2023/06/21 14:22:26 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include "MINISHELL/execution/vars.h"

struct s_ms
{
	int					ipc[2];
	struct s_ms_vars	vars;
};

int		ms_init(struct s_ms *ms);

int		ms_free(struct s_ms *ms);

void	ms_ipc_send(struct s_ms *ms, char byte);

char	ms_ipc_receive(struct s_ms *ms);

#endif
