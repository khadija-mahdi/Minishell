/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:09:53 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/16 10:29:15 by kmahdi           ###   ########.fr       */
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
