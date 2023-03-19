/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_builtins.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:27:03 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/19 07:57:51 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

// t_data *init_export(t_data *dat, m_node *node)
// {
// 	char **env;
// 	t_data *data;
// 	int ac;
	
// 	ac = 1;
// 	env = get_env(NULL);
// 	data = malloc(sizeof(t_data));
// 	if (!data)
// 		return (NULL);
// 	data->export_len = 0;
// 	while(node->arguments[ac])
// 		ac++;
// 	while(env[data->export_len])
// 		data->export_len++;
// 	if (ac > 1)
// 		data->export_len += ac;
// 	data->export =  malloc((data->export_len) * sizeof(char *));
// 	return(data);
// }



// char **add_export(m_node *node, char **env, t_data *data, int ac)
// {
// 	int i ;
	
// 	i = 1;
// 	while(i < ac)
// 	{
// 		data->export[data->export_len] = node->arguments[i];
// 		i++;
// 		data->export_len++;
// 	}
// 	printf("%d\n", data->export_len);
// 	data->export[data->export_len] = NULL;
// 	return (data->export);
// }
// char **get_export(m_node *node, t_data *data) 
// {
// 	int i;
// 	int len = 0;
// 	int ac;
// 	char **env = get_env(NULL);
	
// 	while (env[len])
//         len++;
// 	ac = 1;
// 	while(node->arguments[ac])
// 		ac++;
// 	i = 0;
// 	while(i < len)
// 	{
// 		data->export[i] = env[i];
// 		i++;
// 	}
// 	sorted_list(data->export, len);
// 	if(ac > 1)
// 	{
// 		i = 1;
// 		while(i < ac)
// 		{
// 			data->export[len] = node->arguments[i];
// 			i++;
// 			data->export_len++;
// 			len++;
// 		}
// 		printf("%d\n", data->export_len);
// 		data->export[len] = NULL;
// 	}
// 	data->export[len] = NULL;
// 	return (data->export);
// }

// void add_new_value(m_node *node,t_data *data)
// {
// 	int i = 1;
// 	char *name;
// 	char *value;
// 	int start = 0;

	
// 	while(*data->export)
// 	{
// 		i = 1;
// 		printf("export = %s\n, arg = %s\n", *data->export, node->arguments[i]);
// 		if(!strncmp(*data->export ,node->arguments[i], ft_strlen(node->arguments[i]))
// 			&& (*data->export)[ft_strlen(node->arguments[i])] == '=')
// 		{
// 			printf("hhh");
// 			start = 0;
// 			while (node->arguments[i][start] != '=' && node->arguments[i][start])
// 					start++;
// 			name = ft_substr(node->arguments[1], 0, start);
// 			value = ft_substr(node->arguments[1] , start , ft_strlen(node->arguments[1]));
// 			printf("name = %s\n value = %s\n",name, value);
// 		}
// 		data->export++;
// 		i++;
// 	}		
// }

 


// void parce_arguments(t_data *data, m_node *node)
// {
// 	data->export = get_export(node, data);
// 	while(*node->arguments)
// 	{
// 		if(is_)
// 	}
// }


