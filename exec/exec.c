#include "exec.h"

void	exec(t_list *list)
{
	char **env;
	
	
	if (list == NULL)
		return ;
	m_node *node = (m_node *)list->content;
	if (!node)
		return ;
	if(!node->command || !node->arguments[0])
		return ;
	env = get_env(NULL);
	// if(ft_strcmp(node->command ,"exit")
		exit_command(node);
	unset_command(node);
	cd_command(node);
	env_command(node);
	export_command(node);
	export_only(node);
	echo_command(node);
	pwd_command(node);
}