/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:53:24 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/19 09:28:11 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../exec.h"

void builtins(m_node *node)
{
	char	**env;
	char	**export;
	
	env = get_env(NULL);
	export = get_export(NULL);
	exit_command(node);
	cd_command(node);
	pwd_command(node);
	echo_command(node);
	export_only(node, export, env);
	unset_command(node, env);
	// unset_command(node, export);
	env_command(node);
}