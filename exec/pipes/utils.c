/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:09:53 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/16 11:44:57 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

int	is_builtins(char *s)
{
	if (is_equal(s, "exit") || is_equal(s, "cd") || is_equal(s, "echo")
		|| is_equal(s, "pwd") || is_equal(s, "export") || is_equal(s, "unset")
		|| is_equal(s, "env") || is_equal(s, "EXIT") || is_equal(s, "CD")
		|| is_equal(s, "ECHO") || is_equal(s, "PWD")
		|| is_equal(s, "EXPORT") || is_equal(s, "UNSET")
		|| is_equal(s, "ENV"))
		return (1);
	return (0);
}

void	redirection(t_node *node)
{
	if (node->output_file != NONE && node->output_file != NO_FILE
		&& node->output_file != ERROR)
	{
		if (dup2(node->output_file, 1) < 0)
			exit_msg("DUP", 1);
	}
	if (node->input_file != NONE && node->input_file != NO_FILE
		&& node->input_file != ERROR)
	{
		if (dup2(node->input_file, 0) < 0)
			exit_msg("DUP", 1);
	}
}
