/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:49:48 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/29 21:03:11 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void unset_valide(char **str, char **env)
{
	int	i;

	i = 1;
	while (str[i])
	{
		while (ft_strncmp(*env, str[i], ft_strlen(*env)) == 0)
			printf("unset: '%s' : not a valid identifier\n", str[i++]);
		if (!ft_strncmp(*env, str[i], ft_strlen(str[i]))
			&& (*env)[ft_strlen(str[i])] == '=')
			remove_env(env);
		else
			i++;
	}
}
char	**unset_env(char **str, char **env)
{
	int		i;
	int		len;
	char	**tmp;

	tmp = env;
	while (*env)
		unset_valide(str, env++);
	return (tmp);
}

void	unset_command(m_node *node, char **env)
{
	char	**new_env;
	
	new_env = unset_env(node->arguments, env);
	get_env(new_env);
	get_export(new_env);
	// free_list(÷new_env);
}
