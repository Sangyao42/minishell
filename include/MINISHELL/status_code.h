/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_code.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:23:01 by sawang            #+#    #+#             */
/*   Updated: 2023/06/29 12:30:04 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_CODE_H
# define STATUS_CODE_H

typedef enum e_ms_status
{
	PROGRAM_SUCCESS,
	PROGRAM_FAILURE,
	PROGRAM_ERROR
}			t_ms_status;

/**
 * @brief All possible exit codes from a command. This is accessible in the $?
 * variable.
 * 
 * Signal interruptions are handled by adding 128 to the signal number. These
 * are some common signals:
 * 
 * SIGINT (Ctrl + C) has signal number 2.
 * SIGQUIT (Ctrl + \\) has signal number 3.
 * SIGTERM (kill) has signal number 15.
 * SIGKILL (kill -s KILL) has signal number 9.
 * SIGSTP (Ctrl + Z) has signal number 18.
*/
typedef enum e_ms_exit_code
{
	EC_SUCCESS = 0,
	EC_FAILURE = 1,
	EC_BUILTIN_BADUSAGE = 2,
	EC_COMMAND_NO_PERMISSION = 126,
	EC_COMMAND_NOT_FOUND = 127,
	EC_SIGNAL_INTERRUPT_BASE = 128,
	EC_SYNTAX_ERROR = 258,
	__EC_NO_SUCH_FILE = 300,
	__EC_IS_A_DIR = 301,
	__EC_INTERNAL_ERROR = 302,
}				t_ms_exit_code;

enum e_ms_exit_code	ms_status_to_exit_code(t_ms_status status);

enum e_ms_exit_code	ms_exit_code_from_signal(int signal);

#endif
