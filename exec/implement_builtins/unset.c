/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:49:48 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/02 07:30:27 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void unset_valid(char **str, char **env)
{
	int	i;

	i = 1;
	while (str && str[i])
	{
		if ((str && str[i]) && ((!ft_isalpha(str[i][0]) || is_forbidden_char(str[i])) || !ft_strncmp(*env, str[i], ft_strlen(*env))))
			printf("unset: '%s' : not a valid identifier\n", str[i]);
		else if ((str && str[i]) && !ft_strncmp(*env, str[i], ft_strlen(str[i]))
			&& (*env)[ft_strlen(str[i])] == '=')
			remove_env(env);
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
		unset_valid(str, env++);
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
