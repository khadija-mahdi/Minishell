/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:45:41 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/16 05:02:20 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void	pwd_command(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		printf("minishell :No such file or directory\n");
	else
		printf("%s\n", pwd);
	free (pwd);
}

int	check_home(void)
{
	char	**env;

	env = get_env(NULL);
	while (env && *env)
	{
		if (!ft_strncmp(*env, "HOME", 4))
			return (1);
		env++;
	}
	return (0);
}

void	cd(t_node *node)
{			
	struct stat	sb;
	char		*pwd;

	pwd = getcwd(NULL, 0);
	if (node->arguments[1] && stat(node->arguments[1], &sb) == 0 && S_ISDIR(sb.st_mode))
		chdir(node->arguments[1]);
	else if (node->arguments[1] && S_ISREG(sb.st_mode))
		printf("cd: %s: Not a directory\n", node->arguments[1]);
	else
		printf("cd: no such file or directory: %s\n", node->arguments[1]);
	if (!pwd)
		perror("chdir: error retrieving current directory:"
			"getcwd: cannot access parent directories: ");
	free (pwd);
}

void	cd_command(t_node *node)
{
	if (!ft_strcmp(node->arguments[1], "~"))
		chdir(getenv("HOME"));
	else if (!node->arguments[1] && !check_home())
		printf("cd : HOME not set\n");
	else if (!node->arguments[1] || !strcmp(node->arguments[1], "~"))
		chdir(getenv("HOME"));
	else
		cd(node);
	update(get_export(NULL));
}
