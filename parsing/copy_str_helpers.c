/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_str_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 02:02:01 by aaitouna          #+#    #+#             */
/*   Updated: 2023/04/16 02:02:03 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*return_value(int mode, t_node *node, char *new_str)
{
	if (mode != 0)
		return (new_str);
	add_arg_t_node(node, new_str);
	return (NULL);
}

int	on_error_clear(t_cp_flags *cp_flags, char *env_value, char *new_str,
		int *index)
{
	free(cp_flags);
	free(env_value);
	if (new_str != NULL)
		free(new_str);
	(*index)++;
	return (-1);
}

int	size_of_env_parts(char *env_value)
{
	char	**parts;
	int		lenght;

	parts = NULL;
	parts = split_by_set(env_value, " \t");
	lenght = size(parts);
	free_list(parts);
	return (lenght);
}

t_cp_flags	*init_flags(int mode, int *qute_flag, int *index_ptr)
{
	t_cp_flags	*cp_flags;

	cp_flags = malloc(sizeof(t_cp_flags));
	cp_flags->mode = mode;
	cp_flags->qute_flag = qute_flag;
	cp_flags->index = index_ptr;
	return (cp_flags);
}

void	reset_qute_flag(t_cp_flags *cp_flags, char *s)
{
	if (*cp_flags->qute_flag == 2 && (s[*cp_flags->index] == '"'
			&& *cp_flags->qute_flag == 2))
		*cp_flags->qute_flag = 0;
}
