/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   promt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:50:53 by aaitouna          #+#    #+#             */
/*   Updated: 2023/04/17 02:42:49 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

char	*get_relative_path(char *HOME, char *w_directory)
{
	int		i;
	char	*relative_dir;

	relative_dir = NULL;
	i = 0;
	while (HOME && w_directory && HOME[i] && w_directory[i] == HOME[i])
		i++;
	relative_dir = ft_str_append(relative_dir, ':');
	relative_dir = ft_str_append(relative_dir, '~');
	while (w_directory && w_directory[i])
		relative_dir = ft_str_append(relative_dir, w_directory[i++]);
	relative_dir = m_safe_strjoin(relative_dir, RESET, 1);
	relative_dir = ft_str_append(relative_dir, '\n');
	relative_dir = ft_str_append(relative_dir, '$');
	relative_dir = ft_str_append(relative_dir, ' ');
	return (relative_dir);
}

char	*basic_prompt(void)
{
	char	*default_prompt;

	default_prompt = NULL;
	default_prompt = m_safe_strjoin(default_prompt,
			m_safe_strjoin(RESET, GREEN, 0), 1);
	default_prompt = m_safe_strjoin("Mini-Shell:",
			default_prompt, 2);
	default_prompt = m_safe_strjoin(default_prompt,
			m_safe_strjoin("$ ", RESET, 0), 2);
	return (default_prompt);
}

char	*get_prompt_text(void)
{
	char	*default_prompt;
	char	*home;
	char	*user;

	home = getenv("HOME");
	user = getenv("USER");
	if (!home || !user)
		return (basic_prompt());
	default_prompt = m_safe_strjoin(user, "@", 0);
	default_prompt = m_safe_strjoin(default_prompt, "Mini-Shell", 1);
	default_prompt = m_safe_strjoin(BOLDMAGENTA, default_prompt, 2);
	default_prompt = m_safe_strjoin(default_prompt, ":$ "RESET, 1);
	return (default_prompt);
}
