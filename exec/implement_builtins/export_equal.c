/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_equal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:25:36 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/02 01:12:15 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

// int	get_start(char *str)
// {
// 	int	start;

// 	start = 0;
// 	while (str[start] != '=' && str[start])
// 		start++;
// 	if (str[start] == '=')
// 		start++;
// 	return (start);
// }
// char	*cpy_new_string(char *new_string, int is_env, char *str)
// {
// 	int	i;
// 	int	j;
// 	int	start;
	
// 	start = get_start(str);
// 	i = 0;
// 	j = 0;
// 	while (j < start)
// 	{
// 		if(str[j] == '+')
// 			j++;
// 		new_string[i++] = str[j++];
// 	}
// 	if (is_env == 0)
// 		new_string[i++] = '\"';
// 	while(str[start])
// 		new_string[i++] = str[start++];
// 	if (is_env == 0)
// 		new_string[i++] = '\"';
// 	new_string[i] = '\0';
// 	return (new_string);
// }

// char *add_quotes(char *str, int is_env)
// {
// 	int		len;
// 	char	*new_string;
	
// 	len = ft_strlen(str)  + 3;
// 	new_string = malloc(len * sizeof(char));
// 	if (!new_string)
// 		return (NULL);
// 	new_string = cpy_new_string(new_string, is_env, str);
// 	return (new_string);
// }



// char *add_plus_string(char **export , char *new_str, int is_env)
// {
// 	int i;
// 	int j ;
// 	int start;
// 	int len;
// 	int is_equal;
// 	char *new_string;
	
// 	i = 0;
// 	start = 0;
// 	int k = 0;
// 	is_equal = -1;
// 	while((new_str[start] != '=') && new_str[start])
// 		start++;
// 	new_str= add_quotes(new_str, is_env);
// 	while (export[i])
// 	{
// 		if (!ft_strncmp(export[i], new_str, start))
// 		{
// 			printf("export : %s\n", export[i]);
// 			is_equal = 0;
// 			break ;
// 		}
// 		i++;
// 	}
// 	j = 0;
// 	int n = 0;
// 	if (!is_equal && export[i])
// 	{
// 		len = ft_strlen(new_str) + ft_strlen(export[i]) + 3;
// 		new_string = malloc(len * sizeof(char));
// 		k = 0;
// 		while (export[i][j] && export[i][j] != '\"')
// 			j++;
// 		if (export[i][j] == '\"' && is_env == 0)
// 			j++;
// 		while(k < j)
// 			new_string[k++] = export[i][n++];
// 		while(export[i][j] && export[i][j] != '\"')
// 		{
// 			if(export[i][j] == '+')
// 				j++;
// 			new_string[k++] = export[i][j++];
// 		}
// 		if (new_str[start] == '\"')
// 			start++;
// 		while(new_str[start])
// 			new_string[k++] = new_str[start++];
// 		new_string[k] = '\0';
// 	}
// 	else
// 		new_string = new_str;
// 	return (new_string);
// }
