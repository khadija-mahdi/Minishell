/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_node.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <aaitouna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:34:44 by aaitouna          #+#    #+#             */
/*   Updated: 2023/02/23 04:35:58 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

m_node	*new_m_node(void)
{
	m_node	*new_node;

	new_node = malloc(sizeof(m_node));
	if (!new_node)
		return (NULL);
	new_node->input_file = NONE;
	new_node->command = NULL;
	new_node->arguments = NULL;
	new_node->output_file = NONE;
	return (new_node);
}
