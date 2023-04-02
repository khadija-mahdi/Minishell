/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:45:41 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/02 03:49:42 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void	pwd_command(m_node *node)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd != NULL)
		printf("%s\n", pwd);
	free (pwd);
}

char	**cd_tilde(m_node *node, struct stat sb)
{
	char	**dir;
	int		i;

	if (node->arguments[1][1] == '/')
	{
		i = 0;
		while (node->arguments[1][i])
		{
			if (node->arguments[1][i] == '~')
				i++;
			dir = ft_split(node->arguments[1], '/');
			i++;
		}
	}
	return (dir);
}

void	cd(m_node *node)
{			
	char		**dir;
	struct stat	sb;

	if (node->arguments[1][0] == '~')
	{
		dir = cd_tilde(node, sb);
		while (*dir)
		{
			if (stat(*dir, &sb) == 0 && S_ISDIR(sb.st_mode))
				chdir(*dir);
			dir++;
		}
	}
	else if (stat(node->arguments[1], &sb) == 0 && S_ISDIR(sb.st_mode))
		chdir(node->arguments[1]);
	else if (ft_strcmp(node->arguments[1], "-"))
		printf("cd: no such file or directory: %s\n", node->arguments[1]);
}

void	cd_command(m_node *node, char **env, char **export)
{
	update(env);
	update(export);
	if (!node->arguments[1] || !strcmp(node->arguments[1], "~"))
		chdir(getenv("HOME"));
	else
		cd(node);
}
