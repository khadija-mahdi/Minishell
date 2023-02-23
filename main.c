/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:52:00 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/22 18:46:17 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main(int ac, char **av, char **env)
{
	char    *input = readline("Enter a command: ");
	char	*program_path;
	int i = 0;
	pwd_command(input);
	
	// program_path = get_path(env, input);

	// printf ("%s", program_path);

}
