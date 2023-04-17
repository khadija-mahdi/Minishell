/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 00:35:08 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/17 01:30:26 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	run_commands(t_list *list)
{
	if (!is_interrupted())
		exec(list);
	else
		write(1, "\n", 1);
}

void	clear_resources(char *line, t_list **list)
{
	ft_lstclear(list, clear_node);
	free(line);
}

void	run_mini(char *line, t_list **list)
{
	add_history(line);
	parse(line, list);
	run_commands(*list);
	clear_resources(line, list);
}
